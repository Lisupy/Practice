
def jmapToSmap(jmap: JavaHashMap[Any, Any]): ScalaHashMap[Any, Any] = {
  import java.util.{HashMap => JavaHashMap}
  import scala.collection.mutable.{HashMap => ScalaHashMap}

  val smap = new ScalaHashMap[Any, Any]()
  for (key <- jmap.keySet.toArray){
    smap += key -> jmap.get(key)
  }
  smap
}


val jmap = new java.util.HashMap[String, String]()
jmap.put("1", "a")
jmap.put("2", "b")


println(jmapToSmap(jmap).mkString("\n"))
