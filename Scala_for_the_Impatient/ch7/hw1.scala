package com{
  package horstmann{
    package impatient{
    }
    package object impatient{
      val impatient_s = ""
    }
  }
  package object horstmann{
    val horstmann_s = ""
  }
}

package com.horstmann.impatient {

  package people {
    class Person {
      val s1 = impatient_s
      //val s2 = horstmann_s //编译不过
    }
  }
}
package coma.horstmann.impatient {

  package people {
    class Person {
      val s = "Person"
    }
  }
}
