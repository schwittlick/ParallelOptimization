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
	int widht;
	int heigth;

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
		setThisClassAsActionListener(this);
		this.view.setVisible(true);
		this.widht = view.getWidth();
		this.heigth = view.getHeight();
		Image image = model.getScaledImage(this.widht, this.heigth);
		this.view.setImage(image);
	}

	/**
	 * 
	 * @param ae
	 */
	private void setThisClassAsActionListener(ActionListener ae) {
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
			model.makeBrighter();
		}
		if (e.getActionCommand().equals(ButtonStats.DARKER)) {
			model.makeDarker();
		}
		
		Image image = model.getScaledImage(this.widht, this.heigth);
		view.setImage(image);
	}
}
