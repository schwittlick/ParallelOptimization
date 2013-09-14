import java.awt.Graphics;
import java.awt.image.BufferedImage;
import java.awt.image.RescaleOp;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.JFrame;

public class ImageTester {

	public ImageTester() {
	}

	public static void main(String[] args) throws IOException {
		ImageFrame frame = new ImageFrame();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
		ImageTester imTester = new ImageTester();
		imTester.run();
	}

	public void run() throws IOException {
		final File file = new File("test.jpg");
		final BufferedImage image = ImageIO.read(file);
	}

	public void testImage(BufferedImage image) throws IOException {
		int clr;
		int red;
		int green;
		int blue;
		int imageWidth = image.getWidth();
		int imageHeight = image.getHeight();
		
		for (int curX = 0; curX < imageWidth; curX++) {
			for (int curY = 0; curY < imageHeight; curY++) {
				clr = image.getRGB(curX, curY);
				red = (clr & 0x00ff0000) >> 16;
				green = (clr & 0x0000ff00) >> 8;
				blue = clr & 0x000000ff;
				// Color Red get cordinates
				if (red == 255) {
					System.out.println(String.format("Coordinate %d %d", curX, curY));
				} else {
					System.out.println("Red Color value = " + red);
					System.out.println("Green Color value = " + green);
					System.out.println("Blue Color value = " + blue);
				}
			}
		}
	}

}