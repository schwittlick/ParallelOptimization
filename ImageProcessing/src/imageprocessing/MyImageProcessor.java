package imageprocessing;

import java.awt.Color;
import java.awt.Image;
import java.awt.image.BufferedImage;
import java.awt.image.RescaleOp;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;

import javax.imageio.ImageIO;

/**
 *
 * @author Dennis Haegler
 * @version 1.0
 * 
 */
public class MyImageProcessor {
	private final int CORES = Runtime.getRuntime().availableProcessors();
	private BufferedImage image;
	private int[] rgba;
	private int width;
	private int height;

	/**
	 * 
	 */
	public MyImageProcessor() {
		try {
			this.image = ImageIO.read(new File("test2.jpg"));
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
		this.initRgbaArray();
		setUpThreads();
	}
	
	/**
	 * 
	 */
	private void initRgbaArray() {
		this.rgba = new int[width * height];
		int offset;
		for (int curY = 1; curY < height; curY++) {
			offset = curY * width;
			for (int curX = 1; curX < width; curX++) {
				rgba[offset + curX] = image.getRGB(curX, curY);
			}
		}
	}

	/*
	 * 
	 */
	private void setUpThreads() {
	}

	/**
	 * 
	 */
	public void invert() {
		Color col;
		int offset;
		for (int curY = 1; curY < height; curY++) {
			offset = curY * width;
			for (int curX = 1; curX < width; curX++) {
				col = new Color(this.rgba[offset + curX], true);
				col = new Color(255 - col.getRed(), 255 - col.getGreen(),
						255 - col.getBlue());
				this.rgba[offset + curX] = col.getRGB();
				image.setRGB(curX, curY, this.rgba[offset + curX]);
			}
		}
	}

	// TODO
	public void threadInvert() {
		int split = height / CORES;
		int buffer = split;
		Runnable run1 = new ImageHandlerThread(image, rgba, 0, split);
		Runnable run2 = new ImageHandlerThread(image, rgba, split, split += buffer);
		Runnable run3 = new ImageHandlerThread(image, rgba, split , split += buffer);
		Runnable run4 = new ImageHandlerThread(image, rgba, split, split += buffer);
		Thread thread1 = new Thread(run1);
		Thread thread2 = new Thread(run2);
		Thread thread3 = new Thread(run3);
		Thread thread4 = new Thread(run4);
		thread1.start();
		thread2.start();
		thread3.start();
		thread4.start();
		
		try {
			thread4.join();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	/**
	 * 
	 */
	public void makeBrighter() {
		RescaleOp rescaleOp = new RescaleOp(1.2f, 15, null);
		rescaleOp.filter(image, image);
	}

	/*
	 * 
	 */
	public void makeDarker() {
		RescaleOp rescaleOp = new RescaleOp(0.8f, 15, null);
		rescaleOp.filter(image, image);
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
