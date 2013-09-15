package ui;

import java.awt.Dimension;
import java.awt.Toolkit;

import javax.swing.*;

public class MainFrame extends JFrame {
	private static final long serialVersionUID = 1L;
	private MainPanel mainPanel;
	
	public MainFrame() {
		mainPanel = new MainPanel();
		this.setUp();
	}
	
	private void setUp() {
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setSize(800, 600);
		this.setContentPane(mainPanel);
		this.setLocationRelativeTo(null);
		this.setVisible(true);
	}
}
