package image.processing;

import java.awt.Color;
import java.awt.Image;
import java.awt.color.ColorSpace;
import java.awt.image.BufferedImage;
import java.awt.image.ColorConvertOp;
import java.awt.image.RescaleOp;
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
			this.image = ImageIO.read(new File("test2.jpg"));
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		//setUpByteArray();
		
	}
	
	private void setUpByteArray() {
		int w = image.getWidth();
		int h = image.getHeight();
		int offset = 0;
		int rgb;
		int red;
		int green;
		int blue;
		
		this.imageAsByte = new byte[w * h];
		for (int height = 0; height < h; h++){
			offset = w * height; 
			
			for (int widht = 0; widht < w; w++) {
				rgb = image.getRGB(widht, height);
		        red = (rgb >> 16) & 0xFF;
		        green = (rgb >> 8) & 0xFF;
		        blue = (rgb & 0xFF);

		        this.imageAsByte[offset + widht] = (byte)((red + green + blue) / 3);
		        
			}
		}
	}
	
	private int[] castImageFromByteToInt(byte[] pixelsin, int w, int h) {
		int[] pixelBuffer = new int[w * h];
		for (int p = 0; p < pixelsin.length; p++) {
			pixelBuffer[p] = pixelsin[p] & 0x0000ff;
		}
		return pixelBuffer;
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
		Color col;
		for (int curY = 1; curY < height; curY++) {
			for (int curX = 1; curX < width; curX++) {
				rgba = image.getRGB(curX, curY);
				col = new Color(rgba, true);
				col = new Color(255 - col.getRed(), 255 - col.getGreen(),
						255 - col.getBlue());
				image.setRGB(curX, curY, col.getRGB());
			}
		}
	}

	public void gaus() {
		System.out.println("GAUS NOT IMPLEMENTED");
	}

	public void realInvert() {
		int height = image.getHeight();
		int width = image.getWidth();
		for (int i = 0; i < height; i++) {
			int offset = i * width;
			for (int j = width; j < width; j++) {
				int pos = offset + j;
				this.imageAsByte[pos] = (byte) (255 - this.imageAsByte[pos]);
			}
		}
	}
	
	public void makeBrighter() {
		RescaleOp rescaleOp = new RescaleOp(1.2f, 15, null);
		rescaleOp.filter(image, image);  
	}
	
	public void makeDarker() {
		RescaleOp rescaleOp = new RescaleOp(0.8f, 15, null);
		rescaleOp.filter(image, image);  
	}
}
