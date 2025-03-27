import Navbar from "../../components/Navbar"
// import { useNavigate } from "react-router-dom";
import React, { useState, useEffect } from 'react';


const AboutPage = () => {
    // const navigate = useNavigate();
    // const [isLoggedIn, setLoggedIn] = useState(false);

    // useEffect(() => {
    //     let token = localStorage.getItem("token");
    //     if (!token) {
    //         navigate("/login")
    //     }
    // }, [isLoggedIn]);
    return (
        <>
            <Navbar />
            <div className="jumbotron text-center">
                <div className="display-4">About Us</div>
                <p className="lead">This is a simple About us page.</p>
            </div>
            <div className="container">
                <section>
                    <p>
                        Lorem ipsum dolor sit amet consectetur adipisicing elit. Quam velit ullam ipsam sunt facilis reprehenderit doloremque officia dolorem expedita nulla. Reprehenderit aperiam in itaque et voluptatibus inventore dicta tenetur non?
                    </p>
                    <p>
                        Lorem ipsum dolor sit amet consectetur adipisicing elit. Natus ut nisi ullam libero praesentium in numquam deleniti necessitatibus quas illo sapiente veritatis, culpa, accusantium similique illum atque ad quod iure omnis nam. Consequatur, recusandae blanditiis necessitatibus molestiae dolorum vero ducimus unde saepe quisquam expedita vel quo praesentium accusamus quaerat, ratione amet iusto est corrupti quos iure reprehenderit sit fugit aliquam magnam? Iure quo ad non reprehenderit voluptate, quos magnam temporibus repellendus, similique esse alias minus excepturi doloribus quisquam culpa neque explicabo totam nesciunt vero itaque obcaecati? Consectetur repellat corrupti sit hic. Reiciendis, voluptatum! Eligendi natus quos, molestiae laudantium laborum esse.
                    </p>
                </section>
            </div>
        </>
    );
}

export default AboutPage;