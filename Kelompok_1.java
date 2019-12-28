
import java.text.*;

import java.util.*;

import javax.swing.JOptionPane;

public class Kelompok_1 {
	//1. Revydo D. S. 	(76)
	//2. Sari Eka N. M. (82)
	//3. Tri Wulandari	(85)
	//4. Willy I. K.	(86)

		
		static int menu,index,status= 0;
	    static Scanner input = new Scanner(System.in);
		static int saldo = 0;
		static ArrayList<Integer> pilihItem, banyakBarang;
		static boolean sudahPilih = false;
		static int sumHarga = 0;

		//Fungsi untuk mencegah agar tidak terjadi input selain angka (char ascii 48-57)
		//oleh Willy 
		static int cekInputAngka(String pertanyaan)
		{
			boolean invalid = true;
			String temp = new String("");
			while (invalid)
			{
				invalid = false;
				System.out.print(pertanyaan);
				temp = input.nextLine();
				for (int i = 0; i < temp.length(); i++)
				{
					if (!(temp.charAt(i) >= 48 && temp.charAt(i) <= 57))
					{
						invalid = true;
					}
				}
				if (invalid) System.out.println("Tidak boleh input selain angka!");
			}
			return Integer.parseInt(temp);
		}

		public static void main(String[] args) {
			
			String input;
			String pass;
			input = JOptionPane.showInputDialog(null, "Inputkan Username! (default: admin)","Login",JOptionPane.INFORMATION_MESSAGE);
			
			if (input.equals("admin")) {
				pass = JOptionPane.showInputDialog(null, "Password (default: admin)");
				if (pass.equals("admin")) {
					JOptionPane.showMessageDialog(null, "Berhasil Login !", "Welcome ^_^", JOptionPane.INFORMATION_MESSAGE);
					
					pilihItem = new ArrayList<Integer>();
					banyakBarang = new ArrayList<Integer>();
					System.out.println("Nota Penjualan");
					penjualan();
					
				} else {
					JOptionPane.showMessageDialog(null, "Password Salah", "Sorry", JOptionPane.ERROR_MESSAGE);
					pass = JOptionPane.showInputDialog(null, "Password");
				}
			} else 
				JOptionPane.showMessageDialog(null, "Username Tidak Terdaftar !!!", "Sorry", JOptionPane.ERROR_MESSAGE);
			
			
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
		
			numb1[index] = cekInputAngka("No.telp\t\t: ");
			
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
			
			for (int i = 0; i < item.length; i++) {
				System.out.println(" " + (i+1) + ". " + item[i] + " = " + harga[i]);
			}
			
			System.out.println("  0. Selesai memilih");
			System.out.println("----------------------------------------------");
			
			int i = 0;
			while (!sudahPilih)
			{
				int temp = cekInputAngka("Pilih item : ");
				if (temp == 0)
				{
					sudahPilih = true;
					continue;
				}
				pilihItem.add(temp);
				temp = cekInputAngka("Banyak barang : ");
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

