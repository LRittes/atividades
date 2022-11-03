package apresentacao;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.JTextField;

public class Calculadora extends JFrame {
    private JPanel painel = new JPanel();
    private JPanel painelEntrada = new JPanel();
    JLabel infoCaixaTextoVal = new JLabel("Digite um valor : ");
    private JTextField caixaTextoVal = new JTextField();
    private JButton botaoAdicionar = new JButton("adicionar");
    private JButton botaoLimpar = new JButton("limpar");
    private JScrollPane painelScrollTabelaResultados = new JScrollPane();
    private JTable tabelaResultados;
    private TabelaResultados resultados = new TabelaResultados();
    private JScrollPane paineScrollTabelaValores = new JScrollPane();
    private JTable tabelaValores;
    private TabelaValores valores = new TabelaValores();
    JLabel infoCaixaTextoGer = new JLabel("Digite um valor : ");
    private JTextField caixaTextoGer = new JTextField();
    private JButton botaoFibonacci = new JButton("Fibonacci");
    private JButton botaoPrimos = new JButton("Primos");
    private JButton botaoFatorial = new JButton("Fatorial");

    public static void main(String[] args) {
        Calculadora frame = new Calculadora();
        frame.setVisible(true);
    }

    public Calculadora() {
        setTitle(" Calculadora Estatastica ");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setBounds(100, 100, 900, 300);
        setContentPane(painel);
        painel.setLayout(null);
        painelEntrada.setBounds(15, 80, 280, 173);
        painelEntrada.setLayout(null);
        painel.add(painelEntrada);
        infoCaixaTextoVal.setBounds(30, 30, 200, 15);
        painelEntrada.add(infoCaixaTextoVal);
        caixaTextoVal.setBounds(30, 50, 200, 20);
        painelEntrada.add(caixaTextoVal);
        botaoAdicionar.setBounds(77, 94, 117, 25);
        painelEntrada.add(botaoAdicionar);
        botaoLimpar.setBounds(77, 136, 117, 25);
        painelEntrada.add(botaoLimpar);
        painelScrollTabelaResultados.setBounds(10, 10, 880, 50);
        painel.add(painelScrollTabelaResultados);
        tabelaResultados = new JTable(resultados);
        painelScrollTabelaResultados.setViewportView(tabelaResultados);
        paineScrollTabelaValores.setBounds(307, 80, 173, 173);
        painel.add(paineScrollTabelaValores);
        tabelaValores = new JTable(valores);
        infoCaixaTextoGer.setBounds(30, 30, 200, 15);
        painelEntrada.add(infoCaixaTextoGer);
        caixaTextoGer.setBounds(30, 50, 200, 20);
        botaoFibonacci.setBounds(77, 94, 117, 25);
        painelEntrada.add(botaoFibonacci);
        botaoPrimos.setBounds(77, 94, 117, 25);
        painelEntrada.add(botaoPrimos);
        botaoFatorial.setBounds(77, 94, 117, 25);
        painelEntrada.add(botaoFatorial);

        paineScrollTabelaValores.setViewportView(tabelaValores);
        botaoLimpar.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent arg0) {
                valores.limpar();
                resultados.atualizar();
            }
        });
    }

}
