import java.util.*;
/*
** Willy Indrayana Komara (M3119086)
*/

//Class yang menggunakan implementasi interface Stack
//Dengan menggunakan fitur generic type (type T)
//Artinya bisa digunakan untuk tipe data/objek apapun
class ALStack<T> implements StackBuatan<T>
{
    //array untuk menyimpan value pada stack
    private ArrayList<T> stackList = null;
    
    //constructor untuk inisialisasi objek dari class StackArr
    public ALStack()
    {
        stackList = new ArrayList<T>();
    }

    //fungsi untuk mengecek apakah stack kosong atau tidak
    //return true jika jumlah tumpukan sama dengan nol, otherwise false
    @Override
    public boolean isEmpty()
    {
        return stackList.size() == 0;
    }

    //fungsi untuk menghapus tumpukan teratas
    @Override
    public T pop()
    {
        //jika stack kosong, throw exception akan dilakukan
        //dan penghapusan tumpukan teratas akan diskip
        if (isEmpty())
        {
            throw new EmptyStackException();
        }
        //array dikurangi sebanyak satu, artinya stack/tumpukan teratas dihapus
        //kemudian return nilai tumpukan teratas (setelah array berkurang 1)
        return stackList.remove(stackList.size() - 1);
    }

    //fungsi untuk menambah elemen pada stack (menumpuk dari atas)
    @Override
    public void push(T item)
    {
        //menambah elemen pada array
        stackList.add(item);
    }

    //fungsi untuk melihat elemen teratas pada stack (tanpa menghapusnya)
    @Override
    public T peek()
    {
        //jika tidak ada elemen pada stack, maak throw exception dilakukan
        if (isEmpty())
        {
            throw new EmptyStackException();
        }
        //return array terbelakang/stack teratas tanpa menghapusnya
        return stackList.get(stackList.size() - 1);
    }

    //fungsi yang mereturn jumlah tumpukan berdasarkan size array
    //size array = size stack
    @Override
    public int size()
    {
        return stackList.size();
    }

    //iterator/pointer dari implementasi ArrayList yang akan digunakan
    //dalam class stack ini
    public Iterator<T> iterator()
    {
        return stackList.iterator();
    }
}

public class StackExample4 {
    public static void main(String[] args)
    {
        ALStack<String> sa = new ALStack<String>();
        
        sa.push("Pink");
        sa.push("Purple");
        sa.push("Red");
        System.out.println("Size Stack: " + sa.size());
        sa.pop();
        System.out.println("Peek Stack: " + sa.peek());
        System.out.println("Size Stack: " + sa.size());

        Iterator it = sa.iterator();
        while(it.hasNext())
        {
            System.out.println("Iterator Value : " + it.next());
        }
    }
}