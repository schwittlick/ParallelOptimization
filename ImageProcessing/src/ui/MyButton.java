package ui;

import java.awt.Dimension;

import javax.swing.JButton;

public class MyButton extends JButton {
	final int WIDTH = 75;
	final int HEIGHT = 25;
	
	public MyButton(String label) {
		this.setPreferredSize(new Dimension(75, 25));
		super.setText(label);
	}
}
