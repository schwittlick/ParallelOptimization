package ui;

import java.awt.Color;
import java.awt.Image;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class ImagePanel extends JPanel {
	private Image image;
	JLabel picLabel;
	
	public ImagePanel() {
		setupImagePanel();
	}
	
	private void setupImagePanel() {
		setBackground(Color.WHITE);
		setSize(375, 278);
	}
	
	private void setUpImage() {
		picLabel = new JLabel(new ImageIcon(image));
		add(picLabel);
	}
	
	public void setImage(Image image) {
		this.image = image;
		setUpImage();
	}
	
	public void changeColor() {
		setBackground(Color.RED);
	}

}
