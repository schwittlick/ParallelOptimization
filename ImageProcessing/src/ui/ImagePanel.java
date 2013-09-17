package ui;

import ij.plugin.Scaler;
import ij.process.ImageProcessor;

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
	private BufferedImage image;
	
	public ImagePanel() {
		setupImagePanel();
		try {
			image = ImageIO.read(new File("test.jpg"));
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		Image scaledImage = image.getScaledInstance(this.getWidth(), this.getHeight(),BufferedImage.SCALE_SMOOTH);
		JLabel picLabel = new JLabel(new ImageIcon(scaledImage));
		add(picLabel);
		setupImagePanel();
	}
	
	private void setupImagePanel() {
		setBackground(Color.WHITE);
		setSize(375, 278);
	}
	
	public void invertImage() {
		
	}
}
