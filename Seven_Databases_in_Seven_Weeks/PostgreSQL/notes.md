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

