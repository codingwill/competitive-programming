import java.util.*;
/*
** Willy Indrayana Komara (M3119086)
*/
public class Percobaan1 
{
    public static void queueExample()
    {
        //deklarasi objek queue dengan menggunakan implementasi linked list
        Queue<String> queue = new LinkedList<String>();

        //penambahan element pada queue secara urut
        queue.add("Java");
        queue.add("DotNet");
        queue.offer("PHP");
        queue.offer("HTML");

        //queue pertama dihapus dan diprint
        System.out.println("remove: " + queue.remove());
        //queue pertama diprint tapi tidak dihapus
        System.out.println("element: " + queue.element());
        //queue pertama dihapus dan diprint
        System.out.println("poll: " + queue.poll());
        //queue pertama diprint tapi tidak dihapus
        System.out.println("peek: " + queue.peek());
    }

    public static void main(String[] args)
    {
        queueExample(); 
    }
}