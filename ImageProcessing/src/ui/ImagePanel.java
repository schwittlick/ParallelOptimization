package ui;

import java.awt.Image;

import javax.swing.JPanel;
import java.awt.Color;

public class ImagePanel extends JPanel {
	Image image;
	
	public ImagePanel() {
		setupImagePanel();
	}
	
	private void setupImagePanel() {
		setBackground(Color.PINK);
		setSize(375, 278);
	}
	
	public void setImage(Image image) {
		this.image = image;
	}
	
	public void invertImage() {
		
	}
}
