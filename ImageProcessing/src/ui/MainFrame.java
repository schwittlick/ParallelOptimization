package ui;

import java.awt.Image;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;

/**
 * 
 * @author Dennis Haegler
 * 
 */
public class MainFrame extends JFrame {
	private static final long serialVersionUID = 1L;
	private MainPanel mainPanel;
	private JButton button;

	/**
	 * Construct the main panel and this on frame.
	 */
	public MainFrame() {
		mainPanel = new MainPanel();
		this.setUp();
	}

	/**
	 * 
	 */
	private void setUp() {
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setSize(800, 600);
		this.setContentPane(mainPanel);
		this.setLocationRelativeTo(null);
	}

	/**
	 * 
	 * @param e
	 */
	public void setActionListener(ActionListener e) {
		this.mainPanel.setActionListener(e);
	}
	
	/**
	 * Sets a new image in the on the view.
	 */
	public void setImage(Image image) {
		this.mainPanel.getImagePanel().setImage(image);
	}
	
	public int getWidth() {
		return this.mainPanel.getWidth();
	}

	public int getHeight() {
		return this.mainPanel.getHeight();
	}

	public void setPanelSize(int width, int height) {
		this.mainPanel.setPanelSize(width, height);
		
	}
}
