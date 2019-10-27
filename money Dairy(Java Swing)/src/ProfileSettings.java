import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * Created by user on 1/2/2017.
 */
public class ProfileSettings implements ActionListener {
    JFrame frame;
    JLabel TittleLb,NameLb, PhoneNumberLb, EmailLb, CountryLb;
    JTextField NameTf, PhoneNumberTf, EmailTf, CountryTf;
    JButton button;
    Container c;
    public ProfileSettings()
    {
        frame = new JFrame();
        frame.setBounds(100,100,600,600);
        frame.setLayout(null);
        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        c = frame.getContentPane();

        TittleLb = new JLabel(" User Information ");
        TittleLb.setBounds(150,20,150,60);
        c.add(TittleLb);
        NameLb = new JLabel("Name: ");
        NameLb.setBounds(10,70,40,20);
        c.add(NameLb);
        NameTf = new JTextField();
        NameTf.setBounds(170,70,200,20);
        c.add(NameTf);
        PhoneNumberLb = new JLabel("Phone Number : ");
        PhoneNumberLb.setBounds(10,100,80,20);
        c.add(PhoneNumberLb);
        PhoneNumberTf = new JTextField();
        PhoneNumberTf.setBounds(170,100,200,20);
        c.add(PhoneNumberTf);
        EmailLb = new JLabel("Email : ");
        EmailLb.setBounds(10,130,50,20);
        c.add(EmailLb);
        EmailTf = new JTextField();
        EmailTf.setBounds(170,130,200,20);
        c.add(EmailTf);
        CountryLb = new JLabel("Country : ");
        CountryLb.setBounds(10,160,100,20);
        c.add(CountryLb);
        CountryTf = new JTextField();
        CountryTf.setBounds(170,160,200,20);
        c.add(CountryTf);

    }
    @Override
    public void actionPerformed(ActionEvent e) {

    }

    public static void main(String[] args) {
        ProfileSettings p = new ProfileSettings();
    }
}
