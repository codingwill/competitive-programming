import java.util.*;
import java.text.*;
import java.io.File;
import java.io.IOException;

public class smallNew {
	static int menu,index,status= 0;
    static Scanner input = new Scanner(System.in);
    
	public static void main(String[] args) 
    {	
        System.out.println("Return Pembelian");
        pembelian();
        System.out.println();
        System.out.println("|||-|||-|||-|||-|||-|||-|||-|||-|||-|||-|||-|||-|||");
        System.out.println();
        System.out.println("Return Penjualan");
        penjualan();
	}
	static void pembelian() 
	{
		String namaPer[] = new String[30];
		String person[] = new String[30];
		String alamat[] = new String[30];
		long numb[] = new long[13];
		Date now = new Date();
		
		System.out.println("Inputkan data pada Return Pembelian berikut : ");
		System.out.println("----------------------------------------------");
		System.out.print("Nama Perusahaan\t: ");
		namaPer[index]=input.nextLine();
		System.out.print("Person\t\t: ");
		person[index]=input.nextLine();
		System.out.print("Alamat\t\t: ");
		alamat[index]=input.nextLine();
		System.out.print("No.telp\t\t: ");
		numb[index]=input.nextLong();
		SimpleDateFormat DateFormatter = new SimpleDateFormat("EEEE, d MMMM yyyy");
		System.out.println("Tanggal\t\t: " + DateFormatter.format(now));
		
		System.out.println("----------------------------------------------");
		System.out.println(" 1. UV Varnis");
		System.out.println(" 2. Isoprofil");
		System.out.println(" 3. Tinta New Graff Magenta");
		System.out.println(" 4. Tinta New Graff Yellow");
		System.out.println(" 5. Tinta New Graff Black");
		System.out.println(" 6. Tinta New Graff Cyan");
		System.out.println(" 7. Tinta Graff hg Magenta");
		System.out.println(" 8. Tinta Graff hg Yellow");
		System.out.println(" 9. Tinta Graff hg Black");
		System.out.println("10. Tinta Graff hg Cyan");
		System.out.println("11. Fontain Supreme");
		System.out.println("12. Plate Power");
		System.out.println("13. Sparegum");
		System.out.println("14. Wash 40");
		System.out.println("----------------------------------------------");
		System.out.println("Pilih item : ");
		for(int i=1;i<=3;i++) {
			menu = input.nextInt();
		
		System.out.println("----------------------------------------------");
		switch(menu) {
		case 1 : System.out.println(" 1. UV Varnis");break;
		case 2 : System.out.println(" 2. Isoprofil");break;
		case 3 : System.out.println(" 3. Tinta New Graff Magenta");break;
		case 4 : System.out.println(" 4. Tinta New Graff Yellow");break;
		case 5 : System.out.println(" 5. Tinta New Graff Black");break;
		case 6 : System.out.println(" 6. Tinta New Graff Cyan");break;
		case 7 : System.out.println(" 7. Tinta Graff hg Magenta");break;
		case 8 : System.out.println(" 8. Tinta Graff hg Yellow");break;
		case 9 : System.out.println(" 9. Tinta Graff hg Black");break;
		case 10 : System.out.println("10. Tinta Graff hg Cyan");break;
		case 11 : System.out.println("11. Fontain Supreme");break;
		case 12 : System.out.println("12. Plate Power");break;
		case 13 : System.out.println("13. Sparegum");break;
		case 14 : System.out.println("14. Wash 40");break; }}
		
		System.out.println("----------------------------------------------");

		System.out.println("Status Pembayaran :");
		System.out.println("1.Lunas");
		System.out.println("2.Kredit");
		System.out.println("Pilih yang mana?");
			status = input.nextInt();
		if(status==1) {
			System.out.println("Status Pembayaran yang Dipilih : Lunas");
		}else if(status==2) {
			System.out.println("Status Pembayaran yang Dipilih : Kredit");
		}else {
			System.out.println("Status yang anda pilih tidak ada");
		}
	}
	
	static void penjualan() 
	{
		String namaPer1[] = new String[30];
		String person1[] = new String[30];
		String alamat1[] = new String[30];
		long numb1[] = new long[13];
		Date now1 = new Date();
		
		System.out.println("Inputkan data pada Return Pembelian berikut : ");
		System.out.println("----------------------------------------------");
		System.out.println("Nama Perusahaan\t: ");
		namaPer1[index]=input.nextLine();
		System.out.print("Person\t\t: ");
		person1[index]=input.nextLine();
		System.out.print("Alamat\t\t: ");
		alamat1[index]=input.nextLine();
		System.out.print("No.telp\t\t: ");
		numb1[index]=input.nextLong();
		SimpleDateFormat DateFormatter = new SimpleDateFormat("EEEE, d MMMM yyyy");
		System.out.println("Tanggal\t\t: " + DateFormatter.format(now1));
		
		System.out.println("----------------------------------------------");
		System.out.println(" 1. UV Varnis");
		System.out.println(" 2. Isoprofil");
		System.out.println(" 3. Tinta New Graff Magenta");
		System.out.println(" 4. Tinta New Graff Yellow");
		System.out.println(" 5. Tinta New Graff Black");
		System.out.println(" 6. Tinta New Graff Cyan");
		System.out.println(" 7. Tinta Graff hg Magenta");
		System.out.println(" 8. Tinta Graff hg Yellow");
		System.out.println(" 9. Tinta Graff hg Black");
		System.out.println("10. Tinta Graff hg Cyan");
		System.out.println("11. Fontain Supreme");
		System.out.println("12. Plate Power");
		System.out.println("13. Sparegum");
		System.out.println("14. Wash 40");
		System.out.println("----------------------------------------------");
		System.out.println("Pilih item : ");
		for(int i=1;i<=3;i++) 
		{
			menu = input.nextInt();
		}
		System.out.println("----------------------------------------------");
		switch(menu) 
		{
			case 1 : System.out.println(" 1. UV Varnis");break;
			case 2 : System.out.println(" 2. Isoprofil");break;
			case 3 : System.out.println(" 3. Tinta New Graff Magenta");break;
			case 4 : System.out.println(" 4. Tinta New Graff Yellow");break;
			case 5 : System.out.println(" 5. Tinta New Graff Black");break;
			case 6 : System.out.println(" 6. Tinta New Graff Cyan");break;
			case 7 : System.out.println(" 7. Tinta Graff hg Magenta");break;
			case 8 : System.out.println(" 8. Tinta Graff hg Yellow");break;
			case 9 : System.out.println(" 9. Tinta Graff hg Black");break;
			case 10 : System.out.println("10. Tinta Graff hg Cyan");break;
			case 11 : System.out.println("11. Fontain Supreme");break;
			case 12 : System.out.println("12. Plate Power");break;
			case 13 : System.out.println("13. Sparegum");break;
			case 14 : System.out.println("14. Wash 40");break; 
		}
	}
		
		System.out.println("----------------------------------------------");

		System.out.println("Status Pembayaran :");
		System.out.println("1.Lunas");
		System.out.println("2.Kredit");
		System.out.println("Pilih yang mana?");
			status = input.nextInt();
			if(status==1) {
				System.out.println("Status Pembayaran yang Dipilih : Lunas");
			}else if(status==2) {
				System.out.println("Status Pembayaran yang Dipilih : Kredit");
			}
			else 
			{
				System.out.println("Status yang anda pilih tidak ada");
			}	
	}
}