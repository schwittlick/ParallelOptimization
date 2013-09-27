package imageprocessing;

import java.awt.Color;
import java.awt.image.BufferedImage;

/**
 * 
 * @author Dennis Haegler
 */
public class ImageHandlerThread implements Runnable {
	private BufferedImage image;

	public ImageHandlerThread(BufferedImage im) {
		this.image = im;
		
	}

	public void run() {
		Color col;
		int rgba;
		int width = image.getWidth();
		int end = image.getHeight();
		for (int curY = 0; curY < end; curY++) {
			for (int curX = 1; curX < width; curX++) {
				rgba = image.getRGB(curX, curY);
				col = new Color(rgba, true);
				col = new Color(255 - col.getRed(), 255 - col.getGreen(),
						255 - col.getBlue());
				image.setRGB(curX, curY, col.getRGB());
			}
		}

	}

	public BufferedImage getImage() {
		return this.image;
	}
}