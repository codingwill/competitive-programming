import java.text.*;

import java.util.*;

public class Jual {
	
	static int menu,index,status= 0;
    static Scanner input = new Scanner(System.in);
	static int saldo = 0;
	static ArrayList<Integer> pilihItem, banyakBarang;
	static boolean sudahPilih = false;
	static int sumHarga = 0;
	static int i;
	//static int jumlahItem[14];
	public static void main(String[] args) {	
		pilihItem = new ArrayList<Integer>();
		banyakBarang = new ArrayList<Integer>();
		System.out.println("Nota Penjualan");
		penjualan();
	}

	static void penjualan() {
		String namaPer1[] = new String[30];
		String person1[] = new String[30];
		String alamat1[] = new String[30];
		long numb1[] = new long[13];
		Date now1 = new Date();
		
		System.out.println("Inputkan data pada Nota Penjualan berikut : ");
		System.out.println("----------------------------------------------");
		System.out.print("Nama Perusahaan\t: ");
		namaPer1[index]=input.nextLine();
		System.out.print("Person\t\t: ");
		person1[index]=input.nextLine();
		System.out.print("Alamat\t\t: ");
		alamat1[index]=input.nextLine();
		System.out.print("No.telp\t\t: ");
		numb1[index]=input.nextLong();
		SimpleDateFormat DateFormatter = new SimpleDateFormat("EEEE, d MMMM yyyy");
		System.out.println("Tanggal\t\t: " + DateFormatter.format(now1));
		
		String [] item = {"UV Varnis", "Isoprofil", "Tinta New Graff Magenta", 
				"Tinta New Graff Yellow", "Tinta New Graff Black", 
				"Tinta New Graff Cyan", "Tinta Graff hg Magenta", 
				"Tinta Graff hg Yellow", "Tinta Graff hg Black", 
				"Tinta Graff hg Cyan", "Fontain Supreme","Plate Power",
				"Sparegum", "Wash 40"};
		
		int harga[] = {72500, 10000, 85000, 85000, 85000, 
				90000, 87000, 87000, 87000, 92000, 80000, 
				110000, 30000, 17000};

		System.out.println("==============================================");
		System.out.println("|                 DAFTAR HARGA               |");
		System.out.println("==============================================");
		/*
		System.out.println(" 1. " + item[0] + " = " + harga[0]);
		System.out.println(" 2. Isoprofil = " + harga[1]);
		System.out.println(" 3. Tinta New Graff Magenta = " + harga[2]);
		System.out.println(" 4. Tinta New Graff Yellow = " + harga[3]);
		System.out.println(" 5. Tinta New Graff Black = " + harga[4]);
		System.out.println(" 6. Tinta New Graff Cyan = " + harga[5]);
		System.out.println(" 7. Tinta Graff hg Magenta = " + harga[6]);
		System.out.println(" 8. Tinta Graff hg Yellow = " + harga[7]);
		System.out.println(" 9. Tinta Graff hg Black = " + harga[8]);
		System.out.println("10. Tinta Graff hg Cyan = " + harga[9]);
		System.out.println("11. Fontain Supreme = " + harga[10]);
		System.out.println("12. Plate Power = " + harga[11]);
		System.out.println("13. Sparegum = " + harga[12]);
		System.out.println("14. Wash 40 = " + harga[13]);
		*/
		for (i = 0; i < item.length; i++)
		{
			System.out.println((i+1) + ". " + item[i] + " = " + harga[i]);
		}
		System.out.println("0. Selesai memilih");
		System.out.println("----------------------------------------------");

		
		i = 0;
		while (!sudahPilih)
		{
			System.out.print("Pilih item: ");
			int temp = input.nextInt();
			if (temp == 0)
			{
				sudahPilih = true;
				continue;
			}
			pilihItem.add(temp);
			System.out.print("Banyak barang: ");
			temp = input.nextInt();
			banyakBarang.add(temp);
		}
		System.out.println("=============================================");
		System.out.println("|       Daftar Barang Pembelian Anda        |");
		System.out.println("=============================================");

		for (i = 0; i < pilihItem.size(); i++)
		{
			System.out.print((i+1) + ".) " + item[pilihItem.get(i)] + " x " + banyakBarang.get(i));	
			System.out.println(" = " + (harga[pilihItem.get(i)] * banyakBarang.get(i)));	
			sumHarga += harga[pilihItem.get(i)] * banyakBarang.get(i);	
		}
		System.out.println("==============================================");
		System.out.println("Total harga = " + sumHarga);
		System.out.println("==============================================");
	}
}

