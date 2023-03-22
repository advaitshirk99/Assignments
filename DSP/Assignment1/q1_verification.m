% Define two sequences x1 and x2
x1 = [1 2 3 4];
x2 = [5 6 7 8];

% Verify Commutative Property
y1 = linearconv(x1, x2);
y2 = linearconv(x2, x1);
disp("Commutative Property:");
disp("y1 = x1 * x2 = " + y1);
disp("y2 = x2 * x1 = " + y2);
disp("y1 == y2: " + isequal(y1, y2));

% Verify Associative Property
x3 = [9 10 11];
z1 = linearconv(x1, linearconv(x2, x3));
z2 = linearconv(linearconv(x1, x2), x3);
disp("Associative Property:");
disp("z1 = x1 * (x2 * x3) = " + z1);
disp("z2 = (x1 * x2) * x3 = " + z2);
disp("z1 == z2: " + isequal(z1, z2));

% Verify Distributive Property
a = 2;
b = 3;
y1 = linearconv(a*x1, x2) + linearconv(b*x1, x2);
y2 = linearconv((a*x1) + (b*x1), x2);
disp("Distributive Property:");
disp("y1 = (a*x1 + b*x1) * x2 = " + y1);
disp("y2 = a*x1*x2 + b*x1*x2 = " + y2);
disp("y1 == y2: " + isequal(y1, y2));