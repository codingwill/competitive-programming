
public class array2Dimensi {
    public static void main(String[] args)
    {
        String[][] mahasiswa = {{"Ahmad", "M3119032"},
        {"Ibrahim", "M3117033"}, {"Umar", "M3117034"}};
    
        for (int x = 0; x < mahasiswa.length; ++x)
        {
            System.out.println("Nama: " + mahasiswa[x][0]);
            System.out.println("Nama: " + mahasiswa[x][1]);
            System.out.println("------------------------");
        }
    }
}