package ui.button;

import java.awt.event.ActionListener;

import javax.swing.JPanel;

/**
 * 
 * @author Dennis Haegler
 */
public class ButtonPanel extends JPanel {
	private MyButton invertButton;
	private MyButton gausButton;
	private MyButton brighterButton;
	private MyButton darkerButton;

	/**
	 * 
	 */
	public ButtonPanel() {
		invertButton = new MyButton("Invert");
		gausButton = new MyButton("Gaus");
		brighterButton = new MyButton("+");
		darkerButton = new MyButton("-");
		setUp();
	}

	/**
	 * 
	 */
	private void setUp() {
		this.add(invertButton);
		this.add(gausButton);
		this.add(brighterButton);
		this.add(darkerButton);
		this.setActionCommandToButton();
		this.setVisible(true);
	}
	
	/**
	 * 
	 */
	private void setActionCommandToButton() {
		this.invertButton.setActionCommand(ButtonStats.INVERT);
		this.gausButton.setActionCommand(ButtonStats.GAUS);
		this.brighterButton.setActionCommand(ButtonStats.BRIGHTER);
		this.darkerButton.setActionCommand(ButtonStats.DARKER);
	}

	/**
	 * 
	 * @param actionListener
	 */
	public void setActionListener(ActionListener actionListener) {
		invertButton.addActionListener(actionListener);
		gausButton.addActionListener(actionListener);
		brighterButton.addActionListener(actionListener);
		darkerButton.addActionListener(actionListener);
	}
}
