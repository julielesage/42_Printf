/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 22:40:44 by jlesage           #+#    #+#             */
/*   Updated: 2019/12/19 15:26:43 by jlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
va_copy,

c, s, p, d, i, u, x, X, %

       Après  le  caractère  %,  les  éléments  suivant   doivent
       apparaître, dans l'ordre :

       ·      Zéro ou plusieurs attributs :


Vous devez gérer n’importe quelle combinaison de flags ’-0.*’ et la taille de champ minimale

 0      indique  le remplissage avec des zéros. Pour
                     toutes les conversions sauf n, la valeur est
                     complétée  à  gauche  avec  des zéros plutot
                     qu'avec des espaces.  Si une  précision  est
                     fournie avec une conversion numérique (d, i,
                     o, u, i, x, et X), l'attribut 0 est  ignoré.
		0 uniquement avec c, s, p et % ? 
		conversion numerique d, i, o, u, i x, X a faie a part car . precision decimale

              -      (un attribut de largeur négatif) indique que
                     la valeur doit être justifiée sur la  limite
                     gauche  du champ. Sauf pour la conversion n,
                     les valeurs sont complétées à droite par des
                     espaces, plutôt qu'a gauche par des zéros ou
                     des blancs.   Un  attribut  -  surcharge  un
                     attribut 0 si les deux sont fournis.



              caractères  que  cette largeur, elle sera complétée
              par des espaces à gauche (ou à droite si l'attribut
              d'alignement à gauche a été fourni).

       ·      Une  précision eventuelle, sous la forme d'un point
              (`.')  suivi  par  un  nombre.  Si  ce  nombre  est
              absent,   la   précision  est  fixée  à  0.   Cette
              précision indique un nombre minimum de  chiffres  à
              faire  apparaître  lors des conversions d, i, o, u,
              x, et X, le nombre de décimales à faire  apparaître
              pour  les conversions e, E, et f, le nombre maximum
              de chiffres significatifs pour g et G, et le nombre
              maximum de caractères à imprimer pour la conversion
              s.

       *      Le champ de largeur ou de précision,  ou  les  deux,  sont
              parfois  indiqués  par  un  astérisque `*' à la place d'un
       nombre.  Dans ce cas, un argument int fournit la valeur du
       champ  largeur  ou précision. Un champ de largeur négative

       est traité de manière identique à l'argument  d'ajustement
       à gauche avec une largeur positive. Une précision négative
       est ignorée.

       Les indicateurs de  conversion,  et  leurs  significations
       sont :

       diouxX L'argument  int  (ou  une  variante appropriée) est
              convertie en un chiffre décimal signé (d et i),  un
              chiffre  octal  non-signé  (o),  un chiffre décimal
              non-signé (u), un chiffre héxadécimal non-signé  (x
              et  X).  Les lettres abcdef sont utilisées pour les
              conversions  avec  x,  les  lettres   ABCDEF   sont
              utilisées   pour   les   conversions  avec  X.   La
              précision, si elle est indiquée,  donne  un  nombre
              minimal  de  chiffres  à  faire  apparaître.  Si la
              valeur convertie nécessite moins de chiffres,  elle
              est complétée à gauche avec des zéros.

       c      L'argument entier, de type int, est converti en  un
              unsigned  char,  et  le caractère correspondant est
              affiché.

       s      L'argument de type ``char *'' est supposé  être  un
              pointeur sur un tableau de caractères (pointeur sur
              une chaîne). Les caractères du tableau sont  écrits
              jusqu'au  caractère  NUL final, non compris. Si une
              précision est indiquée,  seul  ce  nombre  de  car­
              actères  sont écrits. Si une précision est fournie,
              il n'y  a  pas  besoin  de  caractère  nul.  Si  la
              précision   n'est   pas  donnée,  ou  si  elle  est
              supérieure à la longueur de la chaîne, le caractère
              NUL final est nécessaire.

       p      L'argument   pointeur,  du  type  ``void  *'',  est
              affiché en héxadécimal, comme avec %#x ou %#lx.

       %      Un caractère `%' est écrit. Il n'y a pas de conver­
              sion. L'indicateur complet est `%%'.

       En  aucun  cas  une petite largeur de champ ne causera une
       troncature d'un champ.  Si le résultat  de  la  conversion
       est  plus  grand  que  le champ prévu, celui-ci est étendu
       pour contenir le résultat.

       L'effet d'ajustement du format %p  avec  des  zéros  (soit
       avec  l'attribut  0,  soit en indiquant une précision), et
       l'effet bénin (en clair : aucun) de l'attribut #  sur  les
       conversions  %n et %p sont non standards. De telles combi­
       naisons doivent être évitées.

VALEUR RENVOYÉE
Si elles réussissent, ces fonctions renvoient le nombre de caractères imprimés, sans compter l'octet nul « \0 » final dans les chaînes. 

Chaîne de format
Le format de conversion est indiqué par une chaîne de caractères, commençant et se terminant dans son état de décalage initial. La chaîne de format est composée d'indicateurs : les caractères ordinaires (différents de %), qui sont copiés sans modification sur la sortie, et les spécifications de conversion, qui sont mises en correspondance avec les arguments suivants. Les spécifications de conversion sont introduites par le caractère %, et se terminent par un indicateur de conversion. Entre eux peuvent se trouver (dans l'ordre), zéro ou plusieurs attributs, une valeur optionnelle de largeur minimal de champ, une valeur optionnelle de précision, et un éventuel modificateur de longueur.
Les arguments doivent correspondre correctement (après les promotions de types) avec les indicateurs de conversion. Par défaut les arguments sont pris dans l'ordre indiqué, où chaque « * » et chaque indicateur de conversion réclament un nouvel argument (et où l'insuffisance en arguments est une erreur). On peut aussi préciser explicitement quel argument prendre, en écrivant, à chaque conversion, « %m$ » au lieu de « % », et « *m$ » au lieu de « * ». L'entier décimal m indique la position dans la liste d'arguments, l'indexation commençant à 1. Ainsi,


printf("%*d", width, num);

et

printf("%2$*1$d", width, num);

sont équivalents. La seconde notation permet de répéter plusieurs fois le même argument. Le standard C99 n'autorise pas le style utilisant « $ », qui provient des Spécifications Single Unix. Si le style avec « $ » est utilisé, il faut l'employer pour toutes conversions prenant un argument, et pour tous les arguments de largeur et de précision, mais on peut le mélanger avec des formats « %% » qui ne consomment pas d'arguments. Il ne doit pas y avoir de sauts dans les numéros des arguments spécifiés avec « $ ». Par exemple, si les arguments 1 et 3 sont spécifiés, l'argument 2 doit aussi être mentionné quelque part dans la chaîne de format.
Pour certaines conversions numériques, un caractère de séparation décimale (le point par défaut) est utilisé, ainsi qu'un caractère de regroupement par milliers. Les véritables caractères dépendent de la localisation LC_NUMERIC. La localisation POSIX utilise « . » comme séparateur décimal, et n'a pas de caractère de regroupement. Ainsi,


printf("%aq.2f", 1234567.89);

s'affichera comme « 1234567.89 » dans la localisation POSIX, « 1 234 567,89 » en localisation fr_FR, et « 1.234.567,89 » en localisation da_DK.  

Caractère d'attribut
Le caractère % peut être éventuellement suivi par un ou plusieurs attributs suivants :
#
indique que la valeur doit être convertie en une autre forme. Pour la conversion o le premier caractère de la chaîne de sortie vaudra zéro (en ajoutant un préfixe 0 si ce n'est pas déjà un zéro). Pour les conversions x et X une valeur non nulle reçoit le préfixe « 0x » (ou « 0X » pour l'indicateur X). Pour les conversions a, A, e, E, f, F, g, et G le résultat contiendra toujours un point décimal même si aucun chiffre ne le suit (normalement, un point décimal n'est présent avec ces conversions que si des décimales le suivent). Pour les conversions g et G les zéros en tête ne sont pas éliminés, contrairement au comportement habituel. Pour les autres conversions, cet attribut n'a pas d'effet.
0
indique le remplissage avec des zéros. Pour les conversions d, i, o, u, x, X, a, A, e, E, f, F, g, et G, la valeur est complétée à gauche avec des zéros plutôt qu'avec des espaces. Si les attributs 0 et - apparaissent ensemble, l'attribut 0 est ignoré. Si une précision est fournie avec une conversion numérique (d, i, o, u, x, et X), l'attribut 0 est ignoré. Pour les autres conversions, le comportement est indéfini.
-
indique que la valeur doit être justifiée sur la limite gauche du champ (par défaut elle l'est à droite). Sauf pour la conversion n, les valeurs sont complétées à droite par des espaces, plutôt qu'à gauche par des zéros ou des blancs. Un attribut - surcharge un attribut 0 si les deux sont fournis.
aq aq
(une espace) indique qu'une espace doit être laissée avant un nombre positif (ou une chaîne vide) produit par une conversion signée
+
Un signe (+ ou -) doit toujours être imprimé avant un nombre produit par une conversion signée. Par défaut, un signe n'est utilisé que pour des valeurs négatives. Un attribut + surcharge un attribut « espace » si les deux sont fournis.
Les cinq caractères d'attributs ci-dessus sont définis dans le standard C, les spécifications SUSv2 en ajoute un :

aq
Pour les conversions décimales (i, d, u, f, F, g, G) indique que les chiffres d'un argument numérique doivent être groupés par milliers en fonction de la localisation. Remarquez que de nombreuses versions de gcc(1) n'acceptent pas cet attribut et déclencheront un avertissement (warning). SUSv2 n'inclue pas %aqF.
La glibc 2.2 ajoute un caractère d'attribut supplémentaire.

I
Pour les conversions décimales (i, d, u) la sortie emploie les chiffres alternatifs de la localisation s'il y en a. Par exemple, depuis la glibc 2.2.3, cela donnera des chiffres arabes pour la localisation perse (« fa_IR »).
 
Largeur de champ
Un nombre optionnel ne commençant pas par un zéro, peut indiquer une largeur minimale de champ. Si la valeur convertie occupe moins de caractères que cette largeur, elle sera complétée par des espaces à gauche (ou à droite si l'attribut d'alignement à gauche a été fourni). À la place de la chaîne représentant le nombre décimal, on peut écrire « * » ou « *m$ » (m étant entier) pour indiquer que la largeur du champ est fournie dans l'argument suivant, ou dans le m-ième argument, respectivement. L'argument fournissant la largeur doit être de type int. Une largeur négative est considéré comme l'attribut « - » vu plus haut suivi d'une largeur positive. En aucun cas une largeur trop petite ne provoque la troncature du champ. Si le résultat de la conversion est plus grand que la largeur indiquée, le champ est élargi pour contenir le résultat. 

Précision
Une précision éventuelle, sous la forme d'un point (« . ») suivi par un nombre. À la place de la chaîne représentant le nombre décimal, on peut écrire « * » ou « *m$ » (m étant entier) pour indiquer que la précision est fournie dans l'argument suivant, ou dans le m-ième argument, respectivement. L'argument fournissant la précision doit être de type int. Si la précision ne contient que le caractère « . », ou une valeur négative, elle est considérée comme nulle. Cette précision indique un nombre minimum de chiffres à faire apparaître lors des conversions d, i, o, u, x, et X, le nombre de décimales à faire apparaître pour les conversions a, A, e, E, f et F, le nombre maximum de chiffres significatifs pour g et G, et le nombre maximum de caractères à imprimer depuis une chaîne pour les conversions s et S.  


Indicateur de conversion
Un caractère indique le type de conversion à apporter. Les indicateurs de conversion, et leurs significations sont :
d, i
L'argument int est converti en un chiffre décimal signé. La précision, si elle est mentionnée, correspond au nombre minimal de chiffres qui doivent apparaître. Si la conversion fournit moins de chiffres, le résultat est rempli à gauche avec des zéros. Par défaut la précision vaut 1. Lorsque 0 est converti avec une précision valant 0, la sortie est vide.
o, u, x, X
L'argument unsigned int est converti en un chiffre octal non signé (o), un chiffre décimal non signé (u), un chiffre hexadécimal non signé (x et X). Les lettres abcdef sont utilisées pour les conversions avec x, les lettres ABCDEF sont utilisées pour les conversions avec X. La précision, si elle est indiquée, donne un nombre minimal de chiffres à faire apparaître. Si la valeur convertie nécessite moins de chiffres, elle est complétée à gauche avec des zéros. La précision par défaut vaut 1. Lorsque 0 est converti avec une précision valant 0, la sortie est vide.
e, E
L'argument réel, de type double, est arrondi et présenté avec la notation scientifique [-]c.ccce\*(Pmcc dans lequel se trouve un chiffre avant le point, puis un nombre de décimales égal à la précision demandée. Si la précision n'est pas indiquée, l'affichage contiendra 6 décimales. Si la précision vaut zéro, il n'y a pas de point décimal. Une conversion E utilise la lettre E (plutôt que e) pour introduire l'exposant. Celui-ci contient toujours au moins deux chiffres. Si la valeur affichée est nulle, son exposant est 00.
f, F
L'argument réel, de type double, est arrondi, et présenté avec la notation classique [-]ccc.ccc, où le nombre de décimales est égal à la précision réclamée. Si la précision n'est pas indiquée, l'affichage se fera avec 6 décimales. Si la précision vaut zéro, aucun point n'est affiché. Lorsque le point est affiché, il y a toujours au moins un chiffre devant.
SUSv2 ne mentionne pas F et dit qu'il existe une chaîne de caractères représentant l'infini ou NaN. Le standard C99 précise « [-]inf » ou « [-]infinity » pour les infinis, et une chaîne commençant par « nan » pour NaN dans le cas d'une conversion f, et les chaînes « [-]INF » « [-]INFINITY » « NAN* » pour une conversion F.

g, G
L'argument réel, de type double, est converti en style f ou e (ou F ou E pour la conversion G) La précision indique le nombre de décimales significatives. Si la précision est absente, une valeur par défaut de 6 est utilisée. Si la précision vaut 0, elle est considérée comme valant 1. La notation scientifique e est utilisée si l'exposant est inférieur à -4 ou supérieur ou égal à la précision demandée. Les zéros en fin de partie décimale sont supprimés. Un point décimal n'est affiché que s'il est suivi d'au moins un chiffre.
a, A
(C99 mais pas SUSv2). Pour la conversion a, l'argument de type double est transformé en notation hexadécimale (avec les lettres abcdef) dans le style [-]0xh.hhhhp\*(Pmd; Pour la conversion A, le préfixe 0X, les lettres ABCDEF et le séparateur d'exposant P sont utilisés. Il y a un chiffre hexadécimal avant la virgule, et le nombre de chiffres ensuite est égal à la précision. La précision par défaut suffit pour une représentation exacte de la valeur, si une représentation exacte est possible en base 2. Sinon, elle est suffisamment grande pour distinguer les valeurs de type double. Le chiffre avant le point décimal n'est pas spécifié pour les nombres non normalisés, et il est non nul pour les nombres normalisés.

s
S'il n'y a pas de modificateur l, l'argument de type const char * est supposé être un pointeur sur un tableau de caractères (pointeur sur une chaîne). Les caractères du tableau sont écrits jusqu'à l'octet nul « \0 » final, non compris. Si une précision est indiquée, seul ce nombre de caractères sont écrits. Si une précision est fournie, il n'y a pas besoin d'octet nul. Si la précision n'est pas donnée, ou si elle est supérieure à la longueur de la chaîne, l'octet nul final est nécessaire.
Si un modificateur l est présent, l'argument de type const wchar_t * est supposé être un pointeur sur un tableau de caractères larges. Les caractères larges du tableau sont convertis en une séquence de caractères multi-octets (chacun par un appel de wcrtomb(3), avec un état de conversion dans l'état initial avant le premier caractère large), ceci jusqu'au caractère large nul final compris. Les caractères multi-octets résultants sont écris jusqu'à l'octet nul final (non compris). Si une précision est fournie, il n'y a pas plus d'octets écrits que la précision indiquée, mais aucun caractère multi-octet n'est écrit partiellement. Remarquez que la précision concerne le nombre d'octets écrits, et non pas le nombre de caractères larges ou de positions d'écrans. La chaîne doit contenir un caractère large nul final, sauf si une précision est indiquée, suffisamment petite pour que le nombre d'octets écrits la remplisse avant la fin de la chaîne.

C
(dans SUSv2 mais pas dans C99) Synonyme de lc. Ne pas utiliser.
S
(dans SUSv2 mais pas dans C99) Synonyme de ls. Ne pas utiliser.
p
L'argument pointeur, du type void * est affiché en hexadécimal, comme avec %#x ou %#lx.
n
Le nombre de caractères déjà écrits est stocké dans l'entier indiqué par l'argument pointeur de type int *. Aucun argument n'est converti.
m
(Extension glibc.) Afficher la sortie de strerror(errno). Aucun argument n'est nécessaire.
%
Un caractère « % » est écrit. Il n'y a pas de conversion. L'indicateur complet est « %% ».

/*char *fullbuffer(char *buf, char *result, BUFFER_SIZE)
{	
	int i;

	i = ft_strlen(buf);
	while (result[i] != '\0')
	{
		if (ft_strlen(buf) = BUFFER_SIZE)
		{
			ft_putstr_fd(buf, 1);
			ft_bzero(buf);
			i = 0;
		}
		buf[i] = result[i];
		i++;
	}
	return (buf);
}*/


int		conversionchar(char *str, va_list ap, t_buff mybuffer, t_printf format)
{
	int		count;

	count = 0;
	if (str[i] == 'c')
/*S'il n'y a pas de modificateur l, l'argument entier, de type int, est converti en un unsigned char, et le caractère correspondant est affiché. Si un modificateur l est présent, l'argument de type wint_t (caractère large) est converti en séquence multi-octet par un appel à wcrtomb(3), avec un état de conversion débutant dans l'état initial. La chaîne multi-octet résultante est écrite.*/
	{
		mybuffer.buff[mybuffer.j] = va_arg(ap, char);
		mybuffer.j += 1;
		return (1);
	}
	else if (str[i] == 's')
	{
		memnoncpy(mybuffer.buff, va_arg(ap, char *);
		mybuffer.j = ft_strlen(mybuffer.buff);
	}
	else if (str[i] == 'p')


}

int		direction(char *str, va_list ap, t_buff mybuffer, t_printf format)
{
	int		count;

	count = 0;
	if (ischar(str[i], "0123456789" == 1)
//		?????????
	if (is char(str[i], "csp%" == 1)
		count = conversionchar(str, ap, mybuffer, format);
	if (is char(str[i], "diuxX" == 1)
		count = conversionint(str, ap, mybuffer, format);

	return (count);
}

int		checkflags(char *str, va_list ap, t_buff mybuffer, t_printf format)
{
	int i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
		return (-1);
	while (ischar(str[i], "-0.*" == 1)
	{
		if (str[i] == '-')
			format.flagminus = 1;
		if (str[i] == '0')
			format.flagzero = 1;
		if (str[i] == '.')
			format.flagpoint = 1;
		if (str[i] == '*')
			format.flagstar = 1;
		i++;
	}
	count = direction(&str[i], ap, mybuffer, format);
	return (count);
}

int		readstring(const char *str, t_buff mybuffer, va_list ap)
{
	t_printf	format;
	int			i;
	int			count;

	i = -1;
	count = 0;
	mybuffer.j = -1;
	while (str[i++] != '\0' && mybuffer.error == 0)
	{
		if (str[i] = '%' && str[i+1])
		{
			ft_bzero(format, sizeof(t_printf));
			count = checkflags(&str[i+1], ap, mybuffer, format);
			mybuffer.j += count;
		}
		else
		{
			mybuffer.buff[mybuffer.j] = str[i];
			mybuffer.j++;
		}
	}
	mybuffer.buff[format.j + 1] = '\0';
	return (mybuffer.j + 1);
}

int		ft_printf(const char *str, ...)
{
	va_list		ap
	int			count;
	t_buff		mybuffer;

	count = 0;
	va_start(ap, str);
	if (!str)
		return (-1);
	ft_bzero(mybuffer, sizeof(t_buff));
	count = readstring(str, mybuffer, ap);
	write(1, &(mybuffer.buff), mybuffer.len);
	va_end(ap);
	return (count);
}
