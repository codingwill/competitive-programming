import java.util.*;
import javax.swing.*;
import java.awt.*;

public class _java_method
{
    static JFrame frame1;
    static JMenu file;
    static JMenuItem loginAdmin, loginUser, keluar;
    static JMenuBar menuBar;
    static JLabel label;
    public static void main(String args[])
    {
        frame1 = new JFrame("Formulir Pendaftaran Mahasiswa Baru");
        file = new JMenu("Menu");
        label = new JLabel("Tidak memilih apapun.");
        loginAdmin = new JMenuItem("Login Administrator");
        loginUser = new JMenuItem("Login Peserta");
        keluar = new JMenuItem("Keluar");
        menuBar = new JMenuBar();
        keluar.addActionListener(new java.awt.event.ActionListener()
        {
            @Override
            public void actionPerformed(java.awt.event.ActionEvent evt)
            {
                System.out.println("Anda baru saja keluar dari program GUI!");
                System.exit(0);                
            }
        });
        loginAdmin.addActionListener(new java.awt.event.ActionListener()
        {
            @Override
            public void actionPerformed(java.awt.event.ActionEvent evt)
            {
                System.out.println("Anda memilih menu [login admin].");
                label.setText("Anda memilih menu [login admin]");
            }
        });
        loginUser.addActionListener(new java.awt.event.ActionListener()
        {
            @Override
            public void actionPerformed(java.awt.event.ActionEvent evt)
            {
                System.out.println("Anda memilih menu [login peserta].");
                label.setText("Anda memilih menu [login peserta]");
            }
        });
        file.add(loginAdmin);
        file.add(loginUser);
        file.add(keluar);
        menuBar.add(file);

        frame1.setJMenuBar(menuBar);
        frame1.add(label);
        frame1.setSize(720, 480);
        frame1.setLocation(50, 100);
        frame1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame1.setVisible(true);

        /*
        JFrame frame2 = new JFrame();
        frame2.setTitle("Jendela 2");
        frame2.setSize(600,450);
        frame2.setLocation(700,100);
        frame2.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame2.setVisible(true);
        */
    }

    static int tambah(int a, int b)
    {
        return a + b;
    }
}