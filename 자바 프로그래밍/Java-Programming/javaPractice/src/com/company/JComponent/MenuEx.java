package com.company.JComponent;

import javax.swing.*;

public class MenuEx extends JFrame {
    public MenuEx() {
        setTitle("Menu 만들기 예제");
        createMenu();
        setSize(250, 250);
        setVisible(true);
    }

    public void createMenu() {
        JMenuBar mb = new JMenuBar();
        JMenu screenMenu = new JMenu("Screen");

        screenMenu.add(new JMenuItem("Load"));
        screenMenu.add(new JMenuItem("Hide"));
        screenMenu.add(new JMenuItem("ReShow"));
        screenMenu.addSeparator();
        screenMenu.add(new JMenuItem("Exit"));

        mb.add(screenMenu);
        mb.add(new JMenu("Edit"));
        mb.add(new JMenu("Source"));
        mb.add(new JMenu("Project"));
        mb.add(new JMenu("Run"));

        this.setJMenuBar(mb);
    }

    public static void main(String[] args) {
        new MenuEx();
    }
}
