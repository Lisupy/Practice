# installation #
* $ apt-get install -y postgresql-9.1 postgresql-client-9.1 postgresql-contrib-9.1 postgresql-server-dev-9.1 
* $ createdb book
* $ psqldb book
    * book=# create extension tablefunc;
    * book=# create extension fuzzystrmatch;
    * book=# create extension pg_trgm;
    * book=# create extension cube;
    * book=# \q
* $ psql book -c "SELECT '1'::cube;"

# Day 1 #
* CREATE TABLE countries (
    country_code char(2) PRIMARY KEY,
    country_name text    UNIQUE 
  );
  DROP TABLE countries;
* INSERT INTO countries (country_code, country_name)
  VALUES      ('us', 'Unite States'), ('mx', 'mexico'), ('au', 'Australia'), ('gb', 'United Kingdom'), ('de', 'Germany'), ('ll', 'Loompaland');
* INSERT INTO countries
  VALUES ('uk', 'United Kingdom');
* SELECT *
  FROM countries;
* DELETE FROM countries
  WHERE country_code = 'll';
* CREATE TABLE cities (
    name text NOT NULL,
    postal_code varchar(9) CHECK (postal_code <> ''),
    country_code char(2)   REFERENCES countries,
    PRIMARY KEY (country_code, postal_code)
    );
* INSERT INTO cities 
  VALUES ('Toronto', 'M4C1B5', 'ca');
  INSERT INTO cities
  VALUES ('Portland', '87200', 'us');
* UPDATE cities
  SET postal_code = '97205'
  WHERE name = 'Portland';
* SELECT cities.\*, country_name
FROM cities INNER JOIN countries
ON   cities.country_code = countries.country_code;
* CREATE TABLE venues(
    venue_id SERIAL PRIMARY KEY,
    name     varchar(255),
    street_address text,
    type char(7) CHECK (type in ('public', 'private') ) DEFAULT 'public',
    postal_code varchar(9),
    country_code char(2),
    FOREIGN KEY (country_code, postal_code)
    REFERENCES cities (country_code, postal_code) MATCH FULL
    );
* INSERT INTO venues (name, postal_code, country_code)
  VALUES ('Crystal Ballroom', '97205', 'us');
* SELECT v.venue_id, v.name, c.name
  FROM venues v INNER JOIN cities c
  ON v.postal_code=c.postal_code AND v.country_code=c.country_code;
* INSERT INTO venues (name, postal_code, country_code)
  VALUES ('Voodoo Donuts', '97205', 'us') 
  RETURNING venue_id;
* CREATE TABLE events(
    event_id SERIAL PRIMARY KEY,
    title text,
    starts timestamp,
    ends timestamp,                                                      
    venue_id int REFERENCE venues 
    );

* SELECT e.title, v.name
  FROM events e JOIN venues v
  ON   e.venue_id = v.venue_id;
  SELECT e.title, v.name
  FROM events e LEFT JOIN venues v
  ON   e.venue_id = v.venue_id
  ;
* CREATE INDEX event_title
  ON events 
  USING hash (title);
  CREATE INDEX events_starts
  ON events 
  USING btree (starts);
  SELECT *
  FROM   events
  WHERE starts >= '2012-04-01'
  \di
* HW-S1
  http://www.postgresql.org/docs/
  http://www.postgresql.org/docs/faq/
* HW-S2
  \?
  \h
* HW-S3
A value inserted into the referencing column(s) is matched against the values of the referenced table and referenced columns using the given match type. There are three match types: MATCH FULL, MATCH PARTIAL, and MATCH SIMPLE (which is the default). 
MATCH FULL will not allow one column of a multicolumn foreign key to be null unless all foreign key columns are null; if they are all null, the row is not required to have a match in the referenced table. 
MATCH SIMPLE allows any of the foreign key columns to be null; if any of them are null, the row is not required to have a match in the referenced table. 
MATCH PARTIAL is not yet implemented. (Of course, NOT NULL constraints can be applied to the referencing column(s) to prevent these cases from arising.)
* HW-Do1
SELECT pg_class.relname, pg_class.relowner
FROM pg_class  INNER JOIN pg_shadow
ON pg_class.relowner = pg_shadow.usesysid AND pg_shadow.usename = 'darren' AND pg_class.relkind='r';
* HW-Do2
SELECT events.title, countries.country_name
FROM events, venues, countries
WHERE events.venue_id=venues.venue_id AND venues.country_code=countries.country_code;
* HW-Do3
ALTER TABLE venues
ADD active bool DEFAULT true;
ALTER TABLE venues
DROP COLUM active;

# Day2 #
* INSERT INTO events (title, starts, ends, venue_id)
  VALUES ('Moby', '2012-02-06 21:00', '2012-02-06 23:00', (
        SELECT venue_id
        FROM venues
        WHERE name = 'Crystal Ballroom')
      );
* SELECT title, count(\*) OVER (PARTITION BY venue_id) FROM events;
* \i add_event.sql  (github  Seven DataBase Seven Weeks)
  SELECT add_event('House Party', '2012-05-03 23:00', '2012-05-04 02:00', 'Run''s House', '97205', 'us');
* createlang book --list 
* CREATE TABLE logs (
    event_id integer,
    old_title varchar(255),
    old_starts timestamp,
    old_ends   timestamp,
    logged_at timestamp DEFAULT current_timestamp
    );
  \i log_event.sql
  CREATE TRIGGER log_events
  AFTER UPDATE ON events
  FOR EACH ROW EXECUTE PROCEDURE log_event();
  UPDATE events 
  SET ends='2012-05-04 01:00:00'
  WHERE title='House Party';
* CREATE TEMPORARY TABLE month_count(month INT);
  INSERT INTO month_count VALUES (1), (2), (3), (4), (5), (6), (7), (8), (9), (10), (11), (12);
  SELECT * FROM crosstab(
      'SELECT extract(year from starts) as year,
      extract(month from starts) as month, count(*)
      FROM events
      GROUP BY year, month',
      'SELECT * FROM month_count'
      ) AS (
        year int,
        jan int, feb int, mar int, apr int, may int, jun int,
        jul int, aug int, sep int, oct int, nov int, dec int
        ) ORDER BY YEAR;
* \i holiday_view_1.sql
* EXPLAIN VERBOSE
    SELECT * 
    FROM holidays;
* HW-S1 the aggregate functions list
  http://www.postgresql.org/docs/9.1/static/functions-aggregate.html
* HW-S2 GUI tools
  pgAdmin, sudo apt-get install pgadmin3 
* HW-Do1
CREATE RULE delete_venues AS ON DELETE TO venues DO INSTEAD
UPDATE venues
SET active=false
WHERE venue_id=OLD.venue_id;
DROP RULE delete_venues ON DELETE venues;
* HW-Do2
SELECT * FROM crosstab(
    'SELECT extract(year from starts) as year,
    extract(month from starts) as month, count(*)
    FROM events
    GROUP BY year, month',
    'SELECT * FROM generate_series(1, 12)'
    ) AS (
      year int,
      jan int, feb int, mar int, apr int, may int, jun int,
      jul int, aug int, sep int, oct int, nov int, dec int
      ) ORDER BY YEAR;
* HW-Do3
SELECT * FROM crosstab(
    'SELECT extract(month from starts) as month, extract(dow from starts) as dow, count(*)  FROM events GROUP BY month, dow;',
    'SELECT * FROM generate_series(0, 6)'
    ) AS (
      month int, Sun int, Mon int, Tue int, Wed int, Thur int, Fri int, Sat int
      );
