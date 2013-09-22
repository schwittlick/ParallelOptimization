import imageprocessing.MyImageProcessor;
import ui.MainFrame;
import controller.ImageProcessingController;

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
