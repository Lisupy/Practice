import java.lang.System._
println("Password?")

if ("secret" == new String(console.readPassword)) {
  val name = getProperty("user.name")
  out.println(f"Greetings, ${name}!")
}else {
  err.println("Error");
}
