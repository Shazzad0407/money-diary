import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseListener;
import java.io.BufferedReader;
import java.io.FileReader;
/**
 * Created by user on 12/24/2016.
 */
public class Login implements ActionListener,MouseListener{
    JFrame frame = new JFrame("Log In ");
    JLabel userNameLb,passwordLb,createNewOneLb,acountCreateMessegeLb;
    JTextField userNameTf;
    JPasswordField passwordPf;
    JButton loginBt;
    Container c =frame.getContentPane();
    public Login(){
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        c.setLayout(null);
        //JLabel;
        userNameLb = new JLabel("User Name : ");
        passwordLb = new JLabel("Password : ");
        createNewOneLb = new JLabel("Create New One");
        acountCreateMessegeLb = new JLabel("Don't have an acount?");

        //JButton;
        loginBt = new JButton("Log in");
        //setBounds For JButton;
        loginBt.setBounds(350,230,80,25);
        //setBounds for Creating new messege;
        acountCreateMessegeLb.setBounds(200,300,120,20);
        createNewOneLb.setForeground(Color.RED);
        //setBounds for Create new one;
        createNewOneLb.setBounds(320,300,150,20);
        //SetJLabel;
        userNameLb.setBounds(200,150,100,20);
        passwordLb.setBounds(200,190,100,20);
        //JTextField;
        userNameTf = new JTextField();
        passwordPf = new JPasswordField();
        //setBounds for JTextField;
        userNameTf.setBounds(320,150,150,20);
        //JPasswordField;
        passwordPf = new JPasswordField();
        //setBounds for JPasswordField;
        passwordPf.setBounds(320,190,150,20);
        // add
        c.add(userNameLb);
        c.add(userNameTf);
        c.add(passwordLb);
        c.add(passwordPf);
        c.add(loginBt);
        c.add(createNewOneLb);
        c.add(acountCreateMessegeLb);
        loginBt.addActionListener(this);
        createNewOneLb.addMouseListener(this);
        //setBounds for JFrame;
        frame.setBounds(50,50,700,400);
        frame.setResizable(false);
        frame.setVisible(true);
    }
    @Override
    public void actionPerformed(ActionEvent e) {
        if(e.getSource() == loginBt)
        {
            int loginFlag = 0;
            char [] pass1 = passwordPf.getPassword();
            String password1 = new String(pass1);
            if(!(userNameTf.getText().isEmpty() || password1.isEmpty()))
            {
                try{
                    BufferedReader br = new BufferedReader(new FileReader("text/signUp.txt"));
                    String line;
                    while((line = br.readLine())!= null) {
                        String sp[] = line.split("\t");
                        if(sp[0].equals(userNameTf.getText()) && sp[1].equals(password1))
                        {
                            loginFlag=1;
                            br.close();
                            frame.setVisible(false);
                            HomeFrame hFrame = new HomeFrame(userNameTf.getText());

                        }
                    }
                    br.close();
                }catch (Exception e2)
                {}
                if(loginFlag == 0)
                {
                    JOptionPane.showMessageDialog(null,"User Name or Password don't match \n please CORRECT it","messege",JOptionPane.ERROR_MESSAGE);
                }
            }
            else{
                JOptionPane.showMessageDialog(null,"Fillup your field","messege",JOptionPane.ERROR_MESSAGE);
            }
        }
    }
    public void mouseClicked(MouseEvent e){
        // i = the index of the selected row
        if(e.getSource() == createNewOneLb)
        {
            frame.setVisible(false);
            CreateAccount ca = new CreateAccount();
        }
    }
    @Override
    public void mousePressed(MouseEvent e) {
        createNewOneLb.setForeground(Color.LIGHT_GRAY);
    }
    @Override
    public void mouseReleased(MouseEvent e) {
    }
    @Override
    public void mouseEntered(MouseEvent e) {
        createNewOneLb.setForeground(Color.BLUE);
        //for change cursor
        Cursor cur = new Cursor(Cursor.HAND_CURSOR);
        createNewOneLb.setCursor(cur);

    }
    @Override
    public void mouseExited(MouseEvent e) {
        createNewOneLb.setForeground(Color.RED);
    }
}
