package image.processing;

import java.awt.Color;
import java.awt.Image;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;

public class MyImageProcessor {
	private BufferedImage image;
	private byte[] imageAsByte;

	/**
	 * 
	 */
	public MyImageProcessor() {
		try {
			image = ImageIO.read(new File("test.jpg"));
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	/**
	 * 
	 * @return
	 */
	public Image getImage() {
		return this.image;
	}

	/**
	 * 
	 * @param width
	 * @param height
	 * @return
	 */
	public Image getScaledImage(int width, int height) {
		return this.image.getScaledInstance(width, height, Image.SCALE_SMOOTH);
	}

	/**
	 * 
	 */
	public void invert() {
		int width = image.getWidth();
		int height = image.getHeight();
		int rgba;
		for (int curY = 0; curY < height; curY++) {
            for (int curX = 0; curX < width; curX++) {
                rgba = image.getRGB(curX, curY);
                Color col = new Color(rgba, true);
                col = new Color(255 - col.getRed(),
                                255 - col.getGreen(),
                                255 - col.getBlue());
                image.setRGB(curY, curX, col.getRGB());
            }
        }
	}

	public void gaus() {
		//TODO
	}
}
