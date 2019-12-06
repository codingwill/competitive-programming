
import java.util.*;

public class SmallProject {
	public static void main(String args[])
	{
		Scanner input = new Scanner(System.in);
		System.out.print("Masukkan jumlah tim: ");
		int jumlahOrang = input.nextInt();
		int jumlahTim = input.nextInt();
		int maxAnggota = (jumlahOrang/jumlahTim) + 1;
		ArrayList<String> anggota = new ArrayList<String>();
		boolean isAnggota[] = new boolean[jumlahOrang+1];
		isAnggota[0] = true;
		String setTim[][] = new String[jumlahTim][maxAnggota];
		for (int i = 0; i < jumlahOrang; i++)
		{
			System.out.print("Masukkan nama " + (i+1) + ": ");
			String nama = input.next();
			anggota.add(nama);
		}
		System.out.println("Ori: " + anggota);
		Collections.shuffle(anggota);
		System.out.println("Shu: " + anggota);
		
		int iTim = 0, iAnggota = 0;
		while(iAnggota < jumlahOrang)
		{
			for (int i = 0; i < jumlahTim; i++)
			{
				setTim[i][] = 
			}
		}
		/*
		for (int i = 0; i < jumlahOrang; i++)
		{
			int assignTim = (int) Math.round(Math.random() * (jumlahOrang - 1));
			//isAnggota[assignTim] = true;
			while (isAnggota[assignTim])
			{
				assignTim = (int) Math.round(Math.random() * (jumlahOrang - 1));
			}
			setTim[iTim][iAnggota] = anggota[assignTim];
			isAnggota[assignTim] = true;
		}
		*/
	}
}
