## Associative Arrays ##
```php

<?php
  array("red", "blue", "yellow");
?>

<?php
  $a = array('c' => "red",
  1 => "blue",
  2 => "yellow");


 foreach ($a as $ingredient=>$include) {
        echo $include . ' ' . $ingredient . '<br />';
  }
?>

<?php
 $myArray = array("do", "re", "mi");
 print $myArray{2};
 // prints "mi";
?>

<?php
 $array = array("first", "middle", "last");
 echo $array[0];
 // prints "first"

?>

<?php
  $array = ("red", "blue", "green");
  unset($array[3]);
?>

<?php
  unset($array);
?>


<?php
  $langs = array("JavaScript",
  "HTML/CSS", "PHP",
  "Python", "Ruby");

  foreach ($langs as $lang) {
      echo "<li>$lang</li>";
  }

  unset($lang);
?>
```


## endwhile/endswitch ##
```php

while(cond):
   // looped statements go here
endwhile;


switch ($i):

endswitch;
```

## String Function ## 
```php
$myname = "David";

// you can manipulate strings easily
// with built-in funtions too
$partial = substr($myname, 0, 3);
print $partial;
// prints "dav"

$uppercase = strtoupper($myname);
print $uppercase;
// prints "DAVID"

$lowercase = strtolower($uppercase);
print $lowercase;
// prints "david"



$pos = strpos("david", "v");
print $pos;  // prints 2

if (strpos("david","h") === false) {
  print "Sorry, no 'h' in 'david'";
}
// prints the "Sorry" message

```

## Math Function ##
```php
// Round pi down from 3.1416...
$round = round(M_PI);
print $round;  // prints 3

// This time, round pi to 4 places
$round_decimal = round(M_PI, 4);
print $round_decimal; // prints 3.1416


print floor(M_PI); // prints 3

print ceil(M_PI); // prints 4

// prints a number between 0 and 32767
print rand();

// prints a number between 1 and 10
print rand(1,10);
```

## Array Function ##
```php
$fav_bands = array();
array_push($fav_bands, "Maroon 5");
array_push($fav_bands, "Bruno Mars");
array_push($fav_bands, "Nickelback");
array_push($fav_bands, "Katy Perry");
array_push($fav_bands, "Macklemore");

print count($fav_bands); // prints 5



$names = array("david","alana","violet","rory");
sort($names);
// array("alana","david","rory","violet")


$names = array("david","alana","violet","rory");
rsort($names);
// array("violet","rory","david","alana")


$names = array("david","alana","violet","rory");
sort($names);
print join(", ", $names);
// prints alana, david, rory, violet
```

## OO ##
```php
class Classname {
  public $propname = "Some value";
  public $otherProp;

  public function __construct($prop1, $prop2) {
    $this->prop1 = $prop1;
    $this->prop2 = $prop2;
  }
}
$obj1 = new Classname();
$obj1->propname;

property_exists($obj1, "propname");
method_exists($obj, 
```

```php
class Person {
	public $isAlive = true;
	
	function __construct($name) {
	  $this->name = $name;
	}
	
	public function dance() {
	return "I'm dancing!";
	}
	}
	
	$me = new Person("Shane");
	if (is_a($me, "Person")) {
	  echo "I'm a person, ";
	}
	if (property_exists($me, "name")) {
	  echo "I have a name, ";
	}
	if (method_exists($me, "dance")) {
	  echo "and I know how to dance!";
	}

```

* const
* static
* extends