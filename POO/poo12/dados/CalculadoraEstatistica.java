package dados;

import java.util.List;

import java.util.LinkedList;
import java.util.Random;

public class CalculadoraEstatistica implements ISequencia {
    private List<Integer> sequencia;
    private static CalculadoraEstatistica instance = null;

    private CalculadoraEstatistica() {
    }

    public static CalculadoraEstatistica getInstance() {
        if (instance == null) {
            instance = new CalculadoraEstatistica();
        }
        return instance;
    }

    public void adicionarValor(int valor) {
        this.sequencia.add(valor);
    }

    public List<Integer> getValores() {
        return sequencia;
    }

    public void setValores(List<Integer> valores) {
        this.sequencia = valores;
    }

    public void limparValores() {
        this.sequencia.clear();
    }

    @Override
    public int sortear() {
        final Random r = new Random();
        return sequencia.get(r.nextInt(sequencia.size()));
    }

    @Override
    public long somatorio() {
        long soma = 0;
        for (final int x : sequencia) {
            soma += x;
        }
        return soma;
    }

    public double Produtorio() {
        long produto = 1;
        for (final int x : sequencia) {
            produto = produto * x;
        }
        return produto;
    }

    @Override
    public double mediaGeometrica() {
        return Math.pow(mediaAritmetica(), 1.0 / (double) (sequencia.size()));
    }

    @Override
    public double variancia() {
        final double media = mediaAritmetica();
        double soma = 0;
        for (final int x : sequencia) {
            soma += Math.pow(x - media, 2);
        }
        return soma / ((double) (sequencia.size()) - 1);
    }

    @Override
    public double desvioPadra() {
        return Math.sqrt(variancia());
    }

    @Override
    public long amplitude() {
        int maior = sequencia.get(0);
        int menor = sequencia.get(0);
        for (final int x : sequencia) {
            if (x > maior) {
                maior = x;
            }
            if (x < menor) {
                menor = x;
            }
        }
        return maior - menor;
    }

    @Override
    public double mediaAritmetica() {
        return somatorio() / (double) (sequencia.size());
    }

}
