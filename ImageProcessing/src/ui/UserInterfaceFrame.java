package ui;

import java.awt.Dimension;
import java.awt.Toolkit;

import javax.swing.*;

public class UserInterfaceFrame extends JFrame {
	private static final long serialVersionUID = 1L;
	private MainPanel myPanel;
	

	public UserInterfaceFrame() {
		myPanel = new MainPanel();
		this.setUp();
	}
	
	private void setUp() {
		this.setFrameMiddle();
		this.setContentPane(myPanel);
	}
	
	private void setFrameMiddle() {
		Toolkit toolkit = Toolkit.getDefaultToolkit();
		Dimension dim = toolkit.getScreenSize();
		int xPos = (dim.width / 2) - (this.getWidth() / 2);
		int yPos = (dim.height / 2) - (this.getHeight() / 2);
		this.setLocation(xPos, yPos);
	}

}
