package image.processing;
import java.awt.Rectangle;

import ij.IJ;
import ij.ImagePlus;
import ij.gui.NewImage;
import ij.plugin.filter.PlugInFilter;
import ij.process.Blitter;
import ij.process.ImageProcessor;



public class MyImageProcessor implements PlugInFilter {

	/** Init in ImageJ */
	public int setup(String arg, ImagePlus imp) {
		if (arg.equals("about")) {
			showAbout();
			return DONE;
		}
		return DOES_8G + NO_CHANGES;
	}

	/** About Message for the Plug-In. */
	public void showAbout() {
		IJ.showMessage("Graubildtest", "Testprogramm");
	}

	public void run(ImageProcessor ip) {
		int width = ip.getWidth();
		int height = ip.getHeight();
		Rectangle roi = ip.getRoi();

		// create a new image with the same size and copy the pixels of the
		// original image
		ImagePlus corrected = NewImage.createByteImage("Corrected image", width, height, 1, NewImage.FILL_BLACK);
		ImageProcessor correctedImageProcessor = corrected.getProcessor();
		correctedImageProcessor.copyBits(ip, 0, 0, Blitter.COPY);
		
		byte[] inputImage = (byte[]) ip.getPixels();
		byte[] newImage = (byte[]) correctedImageProcessor.getPixels();
		
		
		/*********** An dieser Stelle kann an den einzelnen Pixeln gearbeitet werden. *********/

		// Excample Quick and Dirty

		for (int i = roi.y; i < roi.y + roi.height; i++) {
			int offset = i * width;
			for (int j = roi.x; j < roi.x + roi.width; j++) {
				int pos = offset + j;
				newImage[pos] = (byte) (255 - inputImage[pos]);
			}
		}

		/***************** Ende **********************************************************/

		corrected.show();
		corrected.updateAndDraw();
	}
	
	private int[] castPictureFromByteToInt(byte[] pixelsin, int w, int h) {
		int[] pixelBuffer = new int[w * h];
		for (int p = 0; p < pixelsin.length; p++) {
			pixelBuffer[p] = pixelsin[p] & 0x0000ff;
		}
		return pixelBuffer;
	}
	
	private void makeBinaryPicture(int[] pixelBuffer) {
		for (int i = 0; i < pixelBuffer.length; i++) {
			if (pixelBuffer[i] < 90) {
				pixelBuffer[i] = 0;
			} else {
				pixelBuffer[i] = 255;
			}
		}
	}
}
