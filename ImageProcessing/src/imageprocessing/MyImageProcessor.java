package imageprocessing;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Image;
import java.awt.image.BufferedImage;
import java.awt.image.RescaleOp;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;

import javax.imageio.ImageIO;

/**
 * Manipulates images.
 * 
 * @author Dennis Haegler
 * @version 1.0
 * 
 */
public class MyImageProcessor {
	private final int CORES = Runtime.getRuntime().availableProcessors();
	private BufferedImage image;
	private ArrayList<BufferedImage> subImages;
	private int width;
	private int height;

	/**
	 * Prototype constructor. Loads the file named "test2.jpg" from the class
	 * path. Sets the image up.
	 */
	public MyImageProcessor() {
		try {
			BufferedImage tempImage = ImageIO.read(new File("test2.jpg"));
			BufferedImage img = new BufferedImage(tempImage.getWidth(),
					tempImage.getHeight(), BufferedImage.TYPE_INT_ARGB);
			Graphics2D g = img.createGraphics();
			g.drawImage(tempImage, 0, 0, null);
			g.dispose();
			this.image = img;
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		setUp();
	}

	/**
	 * 
	 */
	private void setUp() {
		this.height = image.getHeight();
		this.width = image.getWidth();
		int subHeight = height / CORES;
		subImages = new ArrayList<BufferedImage>();
		int buffer = 0;
		for (int subImage = 1; subImage <= CORES; ++subImage) {
			BufferedImage img = image.getSubimage(0, buffer, width, subHeight);
			buffer += subHeight;
			subImages.add(img);
		}
	}

	/**
	 * Inverts the colors of the image.
	 */
	public void invert() {
		Color col;
		int width = image.getWidth();
		for (int curY = 1; curY < height; curY++) {
			for (int curX = 1; curX < width; curX++) {
				col = new Color(image.getRGB(curX, curY), true);
				col = new Color(255 - col.getRed(), 255 - col.getGreen(),
						255 - col.getBlue());
				image.setRGB(curX, curY, col.getRGB());
			}
		}
	}

	/**
	 * Inverts the color of the image in the count of threads how many cores are
	 * available from the computer.
	 */
	public void threadInvert() {
		ArrayList<Thread> threads = new ArrayList<Thread>();
		for (BufferedImage img : subImages) {
			Runnable run = new ImageHandlerThread(img);
			threads.add(new Thread(run));
		}
		for (Thread thread : threads) {
			thread.start();
		}
		for (Thread thread : threads) {
			try {
				thread.join();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			};
		}
	}

	/**
	 * 
	 * @return
	 */
	public BufferedImage getImage() {
		return this.image;
	}

	/**
	 * 
	 * @return
	 */
	public int getWidth() {
		return width;
	}

	/**
	 * 
	 * @return
	 */
	public int getHeigth() {
		return height;
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
}