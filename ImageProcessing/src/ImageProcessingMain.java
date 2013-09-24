import imageprocessing.MyImageProcessor;
import ui.MainFrame;
import controller.ProcessingController;

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
		MyImageProcessor model = new MyImageProcessor();
		MainFrame ui = new MainFrame();
		ProcessingController controller = new ProcessingController(ui, model);
	}

}
