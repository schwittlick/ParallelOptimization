package imageprocessing;

import java.awt.Color;
import java.awt.image.BufferedImage;

/**
 * 
 * @author Dennis Haegler
 */
public class ImageHandlerThread implements Runnable {
	private BufferedImage image;
	private int[] rgba;
	private int start;
	private int end;

	public ImageHandlerThread(BufferedImage im, int[] rgba, int start, int end) {
		this.image = im;
		this.rgba = rgba;
		this.start = start;
		this.end = end;
	}

	public void run() {
		Color col;
		int offset = 0;
		int width = image.getWidth();
		for (int curY = start; curY < end; curY++) {
			offset = curY * width;
			for (int curX = 1; curX < width; curX++) {
				col = new Color(rgba[offset + curX], true);
				col = new Color(255 - col.getRed(), 255 - col.getGreen(),
						255 - col.getBlue());
				rgba[offset + curX] = col.getRGB();
				image.setRGB(curX, curY, rgba[offset + curX]);
			}
		}
	}
	
	public BufferedImage getImage() {
		return this.image;
	}
}
