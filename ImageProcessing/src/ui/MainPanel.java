package ui;

import javax.swing.JButton;
import javax.swing.JPanel;
import javax.swing.SpringLayout;

import java.awt.Color;

import javax.swing.SwingConstants;

public class MainPanel extends JPanel {
	private JButton invertButton;
	private JButton gausButton;
	private JButton brighterButton;
	private JButton darkerButton;
	private SpringLayout currentLayout;
	private ImagePanel imagePanel;
	
	public MainPanel() {
		invertButton = new JButton("Invert");
		gausButton = new JButton("Gaus");
		brighterButton = new JButton("+");
		darkerButton = new JButton("-");
		currentLayout = new SpringLayout();
		
		imagePanel = new ImagePanel();
		this.setUp();
	}

	private void setUp() {
		this.setButtonsOnPosition();
		this.setLayout(currentLayout);
		this.add(invertButton);
		this.add(gausButton);
		this.add(brighterButton);
		this.add(darkerButton);
		this.add(imagePanel);
	}
	
	private void setButtonsOnPosition() {
		currentLayout.putConstraint(SpringLayout.WEST, darkerButton, 10, SpringLayout.WEST, this);
		currentLayout.putConstraint(SpringLayout.EAST, darkerButton, -16, SpringLayout.WEST, brighterButton);
		currentLayout.putConstraint(SpringLayout.NORTH, brighterButton, 0, SpringLayout.NORTH, darkerButton);
		currentLayout.putConstraint(SpringLayout.WEST, brighterButton, 0, SpringLayout.WEST, invertButton);
		currentLayout.putConstraint(SpringLayout.EAST, brighterButton, 0, SpringLayout.EAST, invertButton);
		currentLayout.putConstraint(SpringLayout.SOUTH, gausButton, -206, SpringLayout.SOUTH, this);
		currentLayout.putConstraint(SpringLayout.NORTH, darkerButton, 28, SpringLayout.SOUTH, gausButton);
		currentLayout.putConstraint(SpringLayout.NORTH, invertButton, 0, SpringLayout.NORTH, gausButton);
		currentLayout.putConstraint(SpringLayout.WEST, invertButton, 16, SpringLayout.EAST, gausButton);
		currentLayout.putConstraint(SpringLayout.WEST, gausButton, 10, SpringLayout.WEST, this);
	}
}
