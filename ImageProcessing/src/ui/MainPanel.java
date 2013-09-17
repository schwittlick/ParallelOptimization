package ui;

import java.awt.Dimension;
import java.awt.event.ActionListener;

import javax.swing.GroupLayout;
import javax.swing.GroupLayout.Alignment;
import javax.swing.JPanel;

import ui.button.ButtonPanel;

/**
 * 
 * @author Dennis Haegler
 *
 */
public class MainPanel extends JPanel {
	private ButtonPanel buttonPanel;
	private ImagePanel imagePanel;
	private GroupLayout groupLayout;

	/**
	 * 
	 */
	public MainPanel() {
		buttonPanel = new ButtonPanel();
		imagePanel = new ImagePanel();
		groupLayout = new GroupLayout(this);
		setUpLayout();
		this.setUp();
	}
	
	/**
	 * 
	 */
	private void setUpLayout() {
		groupLayout.setHorizontalGroup(
			groupLayout.createParallelGroup(Alignment.LEADING)
			.addGroup(groupLayout.createSequentialGroup()
						.addContainerGap()
						.addComponent(buttonPanel, GroupLayout.PREFERRED_SIZE, 108, GroupLayout.PREFERRED_SIZE)
						.addGap(18)
						.addComponent(imagePanel, GroupLayout.DEFAULT_SIZE, 312, Short.MAX_VALUE)
						.addContainerGap())
			);
			groupLayout.setVerticalGroup(
				groupLayout.createParallelGroup(Alignment.LEADING)
					.addGroup(groupLayout.createSequentialGroup()
						.addGap(17)
						.addGroup(groupLayout.createParallelGroup(Alignment.LEADING)
							.addComponent(buttonPanel, GroupLayout.PREFERRED_SIZE, 128, GroupLayout.PREFERRED_SIZE)
							.addComponent(imagePanel, GroupLayout.PREFERRED_SIZE, 260, GroupLayout.PREFERRED_SIZE))
						.addContainerGap(23, Short.MAX_VALUE))
			);
			setLayout(groupLayout);
	}
	
	/**
	 * 
	 */
	private void setUp() {
		buttonPanel.setPreferredSize(new Dimension(100, 100));
		imagePanel.setPreferredSize(new Dimension(400, 250));
	}
	
	public ImagePanel getImagePanel() {
		return this.imagePanel;
	}
	
	/**
	 * 
	 * @param e
	 */
	public void setActionListener(ActionListener e) {
		this.buttonPanel.setActionListener(e);
	}
}
