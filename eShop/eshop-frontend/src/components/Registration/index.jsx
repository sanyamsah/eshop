import styles from './styles.module.css';
import { useFormik } from 'formik';
import * as Yup from 'yup';
import axios from 'axios';
import { Link } from 'react-router-dom';
import { useState } from 'react';

const Registration = () => {
    const initialValues = {
        name: '',
        username: '',
        email: '',
        password: ''
    };

    const [requestResponse, setRequestResponse] = useState({
        requestMessage: "",
        alertClassName: ""
    });
    // const onSubmit = (values) => {
    //     // console.log(values);
    //     values = {
    //         ...values,
    //         username: values.email
    //         name: values.name,
    //         role: 'USER'
    //     }
    //     axios.post("http://localhost:8080/api/auth/register", values)
    //         .then((response) => {
    //             console.log(response.data);
    //             alert("User Registered Successfully!");
    //         }, (error) => {
    //             console.log(error);
    //             alert("User Registration Failed!")
    //         })
    //         .catch(error => console.log(error));
    // };
    const onSubmit = async (values) => {
        try {
            const userData = {
                ...values,
                username: values.username,
                email: values.email,
                name: values.name,
                role: 'USER'
            };
            const response = await axios
                .post("http://localhost:8080/api/auth/register", userData)
                .then(
                    (response) => setRequestResponse({
                        // requestMessage: response.data.message,
                        requestMessage: "User registered successfully!",
                        alertClassName: "alert alert-success"
                    })
                );
            console.log(response.data);
            // alert("User Registered Successfully!");
        } catch (error) {
            console.error(error);
            setRequestResponse({
                requestMessage: error.response.data.message,
                alertClassName: "alert alert-danger"
            })
            // alert("User Registration Failed!");
        }
    };
    const validationSchema = Yup.object({
        // firstName: Yup.string()
        //     .required("First name is required."),
        // lastName: Yup.string()
        //     .required("Last name is required."),
        name: Yup.string()
            .required("Name is required"),
        username: Yup.string()
            .required("Username is required"),
        email: Yup.string()
            .email("Invalid email format.")
            .required("Email is required."),
        password: Yup.string()
            .required("Password is required.")
            .min(6, "Password length should be at least 6 characters.")
    })
    const formik = useFormik({
        initialValues,
        onSubmit,
        // validate,
        validationSchema,
        validateOnMount: false,
        validateOnBlur: true,
        validateOnChange: true
    });
    return (
        <div className='container'>
            <div className="row">
                <div className="col-md-3"></div>
                <div className="col-md-6">
                    <div className={styles.wrapper}>
                        <div className={requestResponse.alertClassName} role="alert">
                            {requestResponse.requestMessage}
                        </div>
                        <h2 className={styles.heading2}>Register Here</h2>
                        <form onSubmit={formik.handleSubmit}>
                            <div className="form-group">
                                {/* <label>First Name</label>
                                <input
                                    type="text"
                                    className="form-control"
                                    name="firstName"
                                    placeholder='Enter first name'
                                    value={formik.values.firstName}
                                    onChange={formik.handleChange} />
                                {formik.errors.firstName ? <small className='text-danger'>{formik.errors.firstName}<br /></small> : null} */}
                                {/* <label>Last Name</label>
                                <input
                                    type="text"
                                    className="form-control"
                                    name="lastName"
                                    placeholder='Enter last name'
                                    value={formik.values.lastName}
                                    onChange={formik.handleChange}
                                />
                                {formik.errors.lastName ? <small className='text-danger'>{formik.errors.lastName}<br /></small> : null} */}
                                <label>Name</label>
                                <input
                                    type="text"
                                    className="form-control"
                                    name="name"
                                    placeholder='Enter full name'
                                    value={formik.values.name}
                                    onChange={formik.handleChange} />
                                {formik.errors.name ? <small className='text-danger'>{formik.errors.name}
                                    <br /></small> : null}
                                <label>Username</label>
                                <input
                                    placeholder='Enter valid username'
                                    type="text"
                                    className="form-control"
                                    name="username"
                                    value={formik.values.username}
                                    onChange={formik.handleChange} />
                                {formik.errors.username ? <small className='text-danger'>{formik.errors.username}<br /></small> : null}
                                <label>Email</label>
                                <input
                                    placeholder='Enter valid email'
                                    type="email"
                                    className="form-control"
                                    name="email"
                                    value={formik.values.email}
                                    onChange={formik.handleChange} /> <br />
                                {formik.errors.email ? <small className='text-danger'>{formik.errors.email}
                                    <br /></small> : null}
                                <label>Password</label>
                                <input
                                    placeholder='Create strong password'
                                    type="password"
                                    className="form-control"
                                    name="password"
                                    value={formik.values.password}
                                    onChange={formik.handleChange} />
                                {formik.errors.password ? <small className='text-danger'>{formik.errors.password}<br /></small> : null}
                            </div>
                            <input
                                type="submit"
                                value="Register"
                                className="btn btn-primary btn-block"
                                disabled={!formik.isValid}
                            />
                        </form>
                        <br />
                        <p className="text-center">
                            Already Registered? Click Here: <Link to="/login">Login</Link>
                        </p>
                    </div>
                </div>
                <div className="col-md-3"></div>
            </div>
        </div>
    );
}

export default Registration;