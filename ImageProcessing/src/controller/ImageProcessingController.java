package controller;

import image.processing.MyImageProcessor;

import java.awt.Image;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import ui.MainFrame;
import ui.button.ButtonStats;

/**
 * 
 * @author Dennis Haegler
 * 
 */
public class ImageProcessingController implements ActionListener {
	private MainFrame view;
	MyImageProcessor model;

	/**
	 * 
	 * @param view
	 * @param m
	 */
	public ImageProcessingController(MainFrame view, MyImageProcessor m) {
		this.view = view;
		this.model = m;
		this.setUp();
	}
	
	private void setUp() {
		actionListenerMeth(this);
		this.view.setVisible(true);
		Image image = model.getScaledImage(200, 150);
		this.view.setImage(image);
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
		if (e.getActionCommand().equals(ButtonStats.INVERT)) {
			model.invert();
		}
		if (e.getActionCommand().equals(ButtonStats.GAUS)) {
			model.gaus();
		}
		if (e.getActionCommand().equals(ButtonStats.BRIGHTER)) {
			System.out.println("BRIGHTER");
		}
		if (e.getActionCommand().equals(ButtonStats.DARKER)) {
			System.out.println("DARKER");
		}
		Image image = model.getScaledImage(200, 100);
		view.setIconImage(image);
	}
}
