import java.util.*;

public class Formulir
{
	static int menu,index = 0;
    static Scanner input = new Scanner(System.in);
    /*
    void login (String user, String pass)
    {
        if ()
    }
    */
    int a = 3;
    static void pilihProgram (final String jenjang[])
    {
        //moves up text/clear screen
        //for (int i = 0; i < 50; ++i) System.out.println();
        System.out.println("====================================");
        System.out.println("Pilih jenjang perkuliahan: ");
        System.out.println("1. S1");
        System.out.println("2. S2");
        System.out.println("3. S3");
        menu = input.nextInt();
        switch (menu)
        {
        case 1 : 
    		jenjang[index] = "S1"; break;
        case 2 : 
    		jenjang[index] = "S2"; break;
        case 3 : 
    		jenjang[index] = "S3"; break;
        }
    } 
    
    static void pilihS1 (final String Sar1[])
    {
    	System.out.println("====================================");
        System.out.println("Pilih Program Studi: ");
        System.out.println("1. Kedokteran");
        System.out.println("2. Informatika");
        System.out.println("3. Hukum");
        System.out.println("4. Teknik Kimia");
        System.out.println("5. Manajemen");
        System.out.println("6. Seni Rupa");
        menu = input.nextInt();
        switch (menu)
        {
        case 1 : 
        	Sar1[index] = "Kedokteran";break;
        case 2 : 
        	Sar1[index] = "Informatika";break;
        case 3 : 
        	Sar1[index] = "Hukum";break;
        case 4 : 
        	Sar1[index] = "Teknik Kimia";break;
        case 5 : 
        	Sar1[index] = "Manajemen";break;
        case 6 : 
        	Sar1[index] = "Seni Rupa";break;
        
        	
        	}
    }
    public static void main (final String args[])
    {
        //DEKLARASI VARIABEL YANG DIBUTUHKAN UNTUK FORM
        final String user[] = new String[10];
        final String pass[] = new String[10];
        final String nama[] = new String[10];
        final String jenjang[] = new String[10];
        final String sar1[] = new String[10];
        final String email[] = new String[10];
        final String gender[] = new String[10];
        final String birth[] = new String[10];
        final String sekolah[] = new String[10];
        final String ortu[] = new String[10];
        final String alamat[] = new String[10];
        final String prodi[] = new String[10];
        
        //int index = 0;
        System.out.println("Selamat Datang, Silahkan Isi Formulir Untuk Pendaftaran");
        System.out.println("====================================");
        System.out.print("Masukkan nama\t\t: ");
        nama[index] = input.nextLine();
        System.out.print("Masukkan username\t: ");
        user[index] = input.nextLine();
        System.out.print("Masukkan password\t: ");
        pass[index] = input.nextLine();
        System.out.print("Masukkan email\t: ");
        email[index] = input.nextLine();
        clearScreen();
        
        pilihProgram(jenjang);
        System.out.println("Pilih 2 prodi");
        pilihS1(sar1);
        
        System.out.println("Nama    \t\t: "+nama[index]);
        System.out.println("Username\t\t: "+ user[index]);
        System.out.println("Jenjang yang dipilih\t: "+jenjang[index]);
        System.out.println("Prodi yang Dipilih  \t: "+sar1[index]);
       
        
    }

    private static void clearScreen() {
    	try {
    		if(System.getProperty("os.name").contains("Windows")) {
    			new ProcessBuilder("cmd","\c","cls").InheritIO().Start().WaitFor();
    		} else {
    			System.out.print("\033\143");
    		}
    		
    	} catch {
    		System.out.println("Wah engga bisa clear screen gais");
    	} 
    }


}