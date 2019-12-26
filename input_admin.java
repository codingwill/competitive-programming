package HAK_eEE;

import javax.swing.JOptionPane;

public class input_admin {
	
	public static void main (String[] arg) {
		
		String input;
		String pass;
		input = JOptionPane.showInputDialog(null, "Inputkan Username !","Login",JOptionPane.INFORMATION_MESSAGE);
		
		if (input.equals("admin")) {
			pass = JOptionPane.showInputDialog(null, "Password");
			if (pass.equals("admin")) {
				JOptionPane.showMessageDialog(null, "Berhasil Login !", "Welcome ^_^", JOptionPane.INFORMATION_MESSAGE);
				System.exit(0);
			} else {
				JOptionPane.showMessageDialog(null, "Password Salah", "Sorry", JOptionPane.ERROR_MESSAGE);
				pass = JOptionPane.showInputDialog(null, "Password");
			}
		} else {
			JOptionPane.showMessageDialog(null, "Username Tidak Terdaftar !!!", "Sorry", JOptionPane.ERROR_MESSAGE);
			input = JOptionPane.showInputDialog(null, "Inputkan username !");
		}
		
	}
}


		
