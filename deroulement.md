1 - Parsing de ma map :
    - Map rectangulaire -> OK
    - check que la map soit entourée de 1 -> OK
    - check qu'il y ai au moins 1 collectible et une exit -> OK 
    - un seul player -> OK
    - check que le nom de la map soit bien .ber -> OK
2 - Regles de touches :
    - ECHAP ferme la fenetre -> OK
    - Pouvoir se deplacer avec WASD -> TODO
    - Pouvoir fermer le programme avec la croix -> OK
    - 
    -
    -
    -
3 -  Calculer la taille de ma map : 
    - Taille d'une ligne * nombre de lignes -> OK
4 -  Restrictions du jeu : 
    - Faire en sorte de faire bouger le personnage avec mes inputs WASD -> OK
    - Le personnage ne peux pas rentrer dans les murs -> OK
    - Changer la position de base de mon personnage en fonction du P -> OK
    - Changer la position du personnage en fonction des keys -> OK
    Comment faire les actions ? : 
    - Sur chaque Key, je fais un ft_swap de mon P et de l'element a sa gauche droite ou autre
    - Si il veut swap avec un '1', je n'effectue pas l'action
5 - KEYCODES MAC :
    - A = 0 , D = 2 , S = 1 , W = 13
6 - Gestion des collectibles : 