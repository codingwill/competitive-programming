import java.util.*;
/*
** Willy Indrayana Komara (M3119086)
*/

//Implementasi Queue menggunakan LinkedList
//Improvisasi Algoritma oleh Will

class WillQueue<T> implements QueueBuatan<T>
{
    private LinkedList<T> list = null;

    //konstruktor queue menggunakan list
    public WillQueue()
    {
        list = new LinkedList<T>();
    }

    //fungsi untuk mengetahui apakah queue kosong atau tidak
    //jika list kosong maka queue pun kosong
    @Override
    public boolean isEmpty()
    {
        return list.isEmpty();
    }

    //fungsi untuk melihat elemen terkiri/antrian terawal
    @Override
    public T peek()
    {
        return list.getFirst();
    }

    //fungsi untuk melihat sekaligus menghapus elemen terkiri/terawal
    @Override
    public T pop()
    {
        return list.removeFirst();
    }

    //fungsi untuk menambah elemen pada antrian terakhir
    @Override
    public void push(T item)
    {
        list.addLast(item);
    }

    //fungsi untuk mengetahui jumlah elemen pqada queue
    @Override
    public int size()
    {
        return list.size();
    }
}

public class Percobaan2 
{
    public static void main(String[] args)
    {
        WillQueue<String> queue = new WillQueue<String>();

        //penambahan element pada queue secara urut
        queue.push("Java");
        queue.push("DotNet");
        queue.push("PHP");
        queue.push("HTML");

        //queue pertama dihapus dan diprint
        System.out.println("remove: " + queue.pop());
        //queue pertama diprint tapi tidak dihapus
        System.out.println("element: " + queue.peek());
        //print size/banyak elemen pada queue
        System.out.println("size: " + queue.size());
    }
    
}