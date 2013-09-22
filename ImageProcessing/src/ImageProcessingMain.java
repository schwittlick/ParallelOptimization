import controller.ImageProcessingController;
import ij.process.ImageProcessor;
import imageprocessing.MyImageProcessor;
import ui.MainFrame;

/**
 * 
 * @author Dennis Haegler
 *
 */
public class ImageProcessingMain {

	/**
	 * 
	 * @param args
	 */
	public static void main(String[] args) {
		MainFrame ui = new MainFrame();
		MyImageProcessor model = new MyImageProcessor();
		ImageProcessingController controller = new ImageProcessingController(ui, model);
	}

}
