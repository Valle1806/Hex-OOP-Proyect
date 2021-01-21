/******************************************************************************************
 * Autores:                                                                               *
 *                                                                                        *
 * -Christian Camilo Taborda Campiño 1632081-3743.                                        *
 * -Cristian Camilo Vallecilla Cuellar 1628790-3743.                                      *
 * -Juan Sebastián Paz Velásquez 1626846-3743.                                            *
 *                                                                                        *
 * Título: T15.h                                                                          *
 *                                                                                        *
 * Descripción:                                                                           *
 *                                                                                        *
 * -Este programa define la clase "T15" (Tablero 15x15) con sus métodos y atributos.      *
 *                                                                                        *
 * Fecha de Creación: 05 / Diciembre / 2016                                               *
 * Fecha de última modificación: 11 / Diciembre / 2016                                    *
 *                                                                                        *
 ******************************************************************************************
 */

#ifndef T15_H
#define T15_H

#include <QDialog>
#include "Jugador.h"

namespace Ui {
class T15;
}

class T15 : public QDialog
{
    Q_OBJECT

public:
    explicit T15(QWidget *parent, QString modalidad);
    explicit T15(QWidget *parent, QString modalidad, int ** T);
    ~T15();
    int generarBoton(int posX, int posY);
    void marcar(int id, int posX, int posY);
    void guardar();


private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_14_clicked();
    void on_pushButton_15_clicked();
    void on_pushButton_16_clicked();
    void on_pushButton_17_clicked();
    void on_pushButton_18_clicked();
    void on_pushButton_19_clicked();
    void on_pushButton_20_clicked();
    void on_pushButton_21_clicked();
    void on_pushButton_22_clicked();
    void on_pushButton_23_clicked();
    void on_pushButton_24_clicked();
    void on_pushButton_25_clicked();
    void on_pushButton_26_clicked();
    void on_pushButton_27_clicked();
    void on_pushButton_28_clicked();
    void on_pushButton_29_clicked();
    void on_pushButton_30_clicked();
    void on_pushButton_31_clicked();
    void on_pushButton_32_clicked();
    void on_pushButton_33_clicked();
    void on_pushButton_34_clicked();
    void on_pushButton_35_clicked();
    void on_pushButton_36_clicked();
    void on_pushButton_37_clicked();
    void on_pushButton_38_clicked();
    void on_pushButton_39_clicked();
    void on_pushButton_40_clicked();
    void on_pushButton_41_clicked();
    void on_pushButton_42_clicked();
    void on_pushButton_43_clicked();
    void on_pushButton_44_clicked();
    void on_pushButton_45_clicked();
    void on_pushButton_46_clicked();
    void on_pushButton_47_clicked();
    void on_pushButton_48_clicked();
    void on_pushButton_49_clicked();
    void on_pushButton_50_clicked();
    void on_pushButton_51_clicked();
    void on_pushButton_52_clicked();
    void on_pushButton_53_clicked();
    void on_pushButton_54_clicked();
    void on_pushButton_55_clicked();
    void on_pushButton_56_clicked();
    void on_pushButton_57_clicked();
    void on_pushButton_58_clicked();
    void on_pushButton_59_clicked();
    void on_pushButton_60_clicked();
    void on_pushButton_61_clicked();
    void on_pushButton_62_clicked();
    void on_pushButton_63_clicked();
    void on_pushButton_64_clicked();
    void on_pushButton_65_clicked();
    void on_pushButton_66_clicked();
    void on_pushButton_67_clicked();
    void on_pushButton_68_clicked();
    void on_pushButton_69_clicked();
    void on_pushButton_70_clicked();
    void on_pushButton_71_clicked();
    void on_pushButton_72_clicked();
    void on_pushButton_73_clicked();
    void on_pushButton_74_clicked();
    void on_pushButton_75_clicked();
    void on_pushButton_76_clicked();
    void on_pushButton_77_clicked();
    void on_pushButton_78_clicked();
    void on_pushButton_79_clicked();
    void on_pushButton_80_clicked();
    void on_pushButton_81_clicked();
    void on_pushButton_82_clicked();
    void on_pushButton_83_clicked();
    void on_pushButton_84_clicked();
    void on_pushButton_85_clicked();
    void on_pushButton_86_clicked();
    void on_pushButton_87_clicked();
    void on_pushButton_88_clicked();
    void on_pushButton_89_clicked();
    void on_pushButton_90_clicked();
    void on_pushButton_91_clicked();
    void on_pushButton_92_clicked();
    void on_pushButton_93_clicked();
    void on_pushButton_94_clicked();
    void on_pushButton_95_clicked();
    void on_pushButton_96_clicked();
    void on_pushButton_97_clicked();
    void on_pushButton_98_clicked();
    void on_pushButton_99_clicked();
    void on_pushButton_100_clicked();
    void on_pushButton_101_clicked();
    void on_pushButton_102_clicked();
    void on_pushButton_103_clicked();
    void on_pushButton_104_clicked();
    void on_pushButton_105_clicked();
    void on_pushButton_106_clicked();
    void on_pushButton_107_clicked();
    void on_pushButton_108_clicked();
    void on_pushButton_109_clicked();
    void on_pushButton_110_clicked();
    void on_pushButton_111_clicked();
    void on_pushButton_112_clicked();
    void on_pushButton_113_clicked();
    void on_pushButton_114_clicked();
    void on_pushButton_115_clicked();
    void on_pushButton_116_clicked();
    void on_pushButton_117_clicked();
    void on_pushButton_118_clicked();
    void on_pushButton_119_clicked();
    void on_pushButton_120_clicked();
    void on_pushButton_121_clicked();
    void on_pushButton_122_clicked();
    void on_pushButton_123_clicked();
    void on_pushButton_124_clicked();
    void on_pushButton_125_clicked();
    void on_pushButton_126_clicked();
    void on_pushButton_127_clicked();
    void on_pushButton_128_clicked();
    void on_pushButton_129_clicked();
    void on_pushButton_130_clicked();
    void on_pushButton_131_clicked();
    void on_pushButton_132_clicked();
    void on_pushButton_133_clicked();
    void on_pushButton_134_clicked();
    void on_pushButton_135_clicked();
    void on_pushButton_136_clicked();
    void on_pushButton_137_clicked();
    void on_pushButton_138_clicked();
    void on_pushButton_139_clicked();
    void on_pushButton_140_clicked();
    void on_pushButton_141_clicked();
    void on_pushButton_142_clicked();
    void on_pushButton_143_clicked();
    void on_pushButton_144_clicked();
    void on_pushButton_145_clicked();
    void on_pushButton_146_clicked();
    void on_pushButton_147_clicked();
    void on_pushButton_148_clicked();
    void on_pushButton_149_clicked();
    void on_pushButton_150_clicked();
    void on_pushButton_151_clicked();
    void on_pushButton_152_clicked();
    void on_pushButton_153_clicked();
    void on_pushButton_154_clicked();
    void on_pushButton_155_clicked();
    void on_pushButton_156_clicked();
    void on_pushButton_157_clicked();
    void on_pushButton_158_clicked();
    void on_pushButton_159_clicked();
    void on_pushButton_160_clicked();
    void on_pushButton_161_clicked();
    void on_pushButton_162_clicked();
    void on_pushButton_163_clicked();
    void on_pushButton_164_clicked();
    void on_pushButton_165_clicked();
    void on_pushButton_166_clicked();
    void on_pushButton_167_clicked();
    void on_pushButton_168_clicked();
    void on_pushButton_169_clicked();
    void on_pushButton_170_clicked();
    void on_pushButton_171_clicked();
    void on_pushButton_172_clicked();
    void on_pushButton_173_clicked();
    void on_pushButton_174_clicked();
    void on_pushButton_175_clicked();
    void on_pushButton_176_clicked();
    void on_pushButton_177_clicked();
    void on_pushButton_178_clicked();
    void on_pushButton_179_clicked();
    void on_pushButton_180_clicked();
    void on_pushButton_181_clicked();
    void on_pushButton_182_clicked();
    void on_pushButton_183_clicked();
    void on_pushButton_184_clicked();
    void on_pushButton_185_clicked();
    void on_pushButton_186_clicked();
    void on_pushButton_187_clicked();
    void on_pushButton_188_clicked();
    void on_pushButton_189_clicked();
    void on_pushButton_190_clicked();
    void on_pushButton_191_clicked();
    void on_pushButton_192_clicked();
    void on_pushButton_193_clicked();
    void on_pushButton_194_clicked();
    void on_pushButton_195_clicked();
    void on_pushButton_196_clicked();
    void on_pushButton_197_clicked();
    void on_pushButton_198_clicked();
    void on_pushButton_199_clicked();
    void on_pushButton_200_clicked();
    void on_pushButton_201_clicked();
    void on_pushButton_202_clicked();
    void on_pushButton_203_clicked();
    void on_pushButton_204_clicked();
    void on_pushButton_205_clicked();
    void on_pushButton_206_clicked();
    void on_pushButton_207_clicked();
    void on_pushButton_208_clicked();
    void on_pushButton_209_clicked();
    void on_pushButton_210_clicked();
    void on_pushButton_211_clicked();
    void on_pushButton_212_clicked();
    void on_pushButton_213_clicked();
    void on_pushButton_214_clicked();
    void on_pushButton_215_clicked();
    void on_pushButton_216_clicked();
    void on_pushButton_217_clicked();
    void on_pushButton_218_clicked();
    void on_pushButton_219_clicked();
    void on_pushButton_220_clicked();
    void on_pushButton_221_clicked();
    void on_pushButton_222_clicked();
    void on_pushButton_223_clicked();
    void on_pushButton_224_clicked();
    void on_pushButton_225_clicked();

    void on_G_clicked();

private:
    Ui::T15 *ui;
    QString modalidad;
    int empate;
    bool decision;
    Jugador * J1;
    Jugador * J2;
    Tablero * T;
    QString pActual;
    QString pArchivo;
};

#endif // T15_H
