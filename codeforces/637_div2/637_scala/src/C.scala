
import java.io.{BufferedReader, InputStreamReader}
import java.util.StringTokenizer

object C {

    def main(args:Array[String]) : Unit = {
        val br = new BufferedReader(new InputStreamReader(System.in))
        var st : StringTokenizer = new StringTokenizer(br.readLine())
        val cases = st.nextToken().toInt
        var n : Int = 0
        var ans : Boolean = true
        var arr : Array[Int] = Array()
        var prev : Int = 0
        var now : Int = 0
        for (ncase <- 1 to cases) {
            ans = true
            n = br.readLine().toInt
            st = new StringTokenizer(br.readLine())
            prev = st.nextToken().toInt
            for (i <- 1 until (n - 1)) {
                now = st.nextToken().toInt
                if ((prev + 1) < now) ans = false
                prev = now
            }

            if (ans) {
                println("Yes")
            } else {
                println("No")
            }
        }
    }  

}  