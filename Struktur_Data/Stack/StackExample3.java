import java.util.*;
/*
** Willy Indrayana Komara (M3119086)
*/

//Class yang menggunakan implementasi interface Stack
//Dengan menggunakan fitur generic type (type T)
//Artinya bisa digunakan untuk tipe data/objek apapun
class StackArr<T> implements StackBuatan<T>
{
    //array untuk menyimpan value pada stack
    T value[];

    //variabel yang menyatakan jumlah tumpukan dan indexing pada array
    int topOfStack;

    //constructor untuk inisialisasi objek dari class StackArr
    public StackArr(int size)
    {
        value = (T[]) new Object[size];
    }

    //fungsi untuk mengecek apakah stack kosong atau tidak
    //return true jika jumlah tumpukan sama dengan nol, otherwise false
    @Override
    public boolean isEmpty()
    {
        return topOfStack == 0;
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
        //index array dikurangi sebanyak satu, artinya stack/tumpukan teratas dihapus
        //kemudian return nilai tumpukan teratas (setelah index turun 1)
        --topOfStack;
        return value[topOfStack];
    }

    //fungsi untuk menambah elemen pada stack (menumpuk dari atas)
    @Override
    public void push(T item)
    {
        //tumpukan teratas diassign value elemen baru
        //kemudian pointer/index ditambah 1
        value[topOfStack] = item;
        ++topOfStack;
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
        //jika ada elemen, maka index pada array akan berkurang 1, kemudian
        //dilakukan assignment pada variabel temp untuk menaruh nilai
        //tumpukan teratas, lalu dilakukan increment lagi pada index array sebanyak 1
        --topOfStack;
        T temp = value[topOfStack];
        ++topOfStack;
        return temp;
    }

    //fungsi yang mereturn jumlah tumpukan berdasarkan nilai index pada array
    //i-akhir array = size stack
    @Override
    public int size()
    {
        return topOfStack;
    }

    //mengkonversi elemen-elemen pada stack (atau lebih tepatnya array)
    //ke dalam string
    @Override
    public String toString()
    {
        String str = "";
        for (int i = 0; i < topOfStack; ++i)
        {
            str += value[i] + " ";
        }
        return str;
    }
}

public class StackExample3
{
    public static void main(String[] args)
    {
        StackArr<String> sa = new StackArr<String>(10);

        sa.push("Pink");
        sa.push("Purple");
        sa.push("Red");
        System.out.println("Push Stack: " + sa.toString());
        System.out.println("Size Stack: " + sa.size());
        sa.pop();
        System.out.println("Pop Stack: " + sa.toString());
        System.out.println("Peek Stack: " + sa.peek());
        System.out.println("Size Stack: " + sa.size());
    }
}