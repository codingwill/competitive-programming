import java.util.*;

public class array_of_string
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        String arr[] = new String[3];
        for (int i = 0; i < 3; i++)
        {
            arr[i] = "Hello " + i;
        }
        System.out.println(arr[1]);
    }
}
