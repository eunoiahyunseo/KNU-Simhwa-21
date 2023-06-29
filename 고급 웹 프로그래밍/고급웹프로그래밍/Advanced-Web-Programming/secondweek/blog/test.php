<?php
$name = $_POST['name'];
$major = $_POST['major'];
$year = $_POST['year'];
$subjects = $_POST['subjects'];
$major2 = $_POST['major2'];
$major3 = $_POST['major3'];
$email = $_POST['email'];
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>HTML</title>
    <style>
        * {
            font-size: 16px;
            font-family: Consolas, sans-serif;
        }
    </style>
</head>

<body>
    <p>이름 >> <?php echo $name ?></p>
    <p>전공 >> <?php echo $major ?></p>
    <p>학년 >> <?php echo $year ?></p>
    <p>할 수 있는 스택 >> <?php print_r($subjects) ?></p>
    <p>전공2 >> <?php echo $major2 ?></p>
    <p>전공3 >> <?php echo $major3 ?></p>
    <p>이메일 >> <?php echo $email ?></p>

</body>

</html>