import image.processing.ImageProcessor;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import ui.MainFrame;

/**
 * 
 * @author Dennis Haegler
 *
 */
public class ImageProcessingController implements ActionListener {
	private MainFrame view;
	ImageProcessor model;

	/**
	 * 
	 * @param view
	 * @param m
	 */
	public ImageProcessingController(MainFrame view, ImageProcessor m) {
		this.view = view;
		model = m;
		actionListenerMeth(this);
	}

	/**
	 * 
	 * @param ae
	 */
	private void actionListenerMeth(ActionListener ae) {
		view.setActionListener(ae);
	}
	
	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO

	}
}
