package controller;

import imageprocessing.MyImageProcessor;
import imageprocessing.MyTimer;
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
public class ProcessingController implements ActionListener {
	private MainFrame view;
	MyImageProcessor model;
	MyTimer timer;

	/**
	 * 
	 * @param view
	 * @param m
	 */
	public ProcessingController(MainFrame view, MyImageProcessor m) {
		this.timer = new MyTimer();
		this.view = view;
		this.model = m;
		this.setUp();
	}

	private void setUp() {
		setThisClassAsActionListener(this);
		this.view.setVisible(true);
		this.view.setPanelSize(1200, 800);
		int width = view.getWidth();
		int height = view.getHeight();
		Image image = model.getScaledImage(width, height);
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
		timer.start();
		if (e.getActionCommand().equals(ButtonStats.INVERT)) {
			model.invert();
		}
		if (e.getActionCommand().equals(ButtonStats.BRIGHTER)) {
			model.threadInvert();
		}
		if (e.getActionCommand().equals(ButtonStats.DARKER)) {
			model.makeDarker();
		}
		timer.stop();
		System.out.println("Time needed: " + timer.getTime() + " ms");
		Image image = model.getScaledImage(view.getWidth(), view.getHeight());
		view.setImage(image);
	}
}
