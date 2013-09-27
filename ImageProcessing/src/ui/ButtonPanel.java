package ui;

import java.awt.event.ActionListener;

import javax.swing.JPanel;

/**
 * 
 * @author Dennis Haegler
 */
public class ButtonPanel extends JPanel {
	private MyButton invertButton;
	private MyButton threadButton;

	/**
	 * 
	 */
	public ButtonPanel() {
		invertButton = new MyButton("Solo");
		threadButton = new MyButton("multi");
		setUp();
	}

	/**
	 * 
	 */
	private void setUp() {
		this.add(invertButton);
		this.add(threadButton);
		this.setActionCommandToButton();
		this.setVisible(true);
	}
	
	/**
	 * 
	 */
	private void setActionCommandToButton() {
		this.invertButton.setActionCommand(ButtonStats.INVERT);
		this.threadButton.setActionCommand(ButtonStats.THREAD);
	}

	/**
	 * 
	 * @param actionListener
	 */
	public void setActionListener(ActionListener actionListener) {
		invertButton.addActionListener(actionListener);
		threadButton.addActionListener(actionListener);
	}
}
